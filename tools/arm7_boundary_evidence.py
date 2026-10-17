"""Recheck bounded ARM range proposals against original callers and literal loads."""
import hashlib
import struct


def mapped_offset(address, config):
    for module in config['autoloads']:
        if module['runtime_address'] <= address < module['runtime_address']+module['size']:
            return module['payload_offset']+address-module['runtime_address']
    raise ValueError('Address is outside initialized autoload ranges')


def branch_target(word, address):
    displacement=word&0xffffff
    if displacement&0x800000:displacement-=0x1000000
    return address+8+displacement*4


def verify_proposal(proposal, payload, baseline, config):
    if proposal['original_rom_sha1']!=baseline['source_rom_sha1']:
        raise ValueError('Boundary proposal ROM provenance differs')
    claims=[];records=[]
    for row in proposal['ranges']:
        start=int(row['start'],16);code_end=int(row['code_end'],16);end=int(row['end'],16)
        if not start<code_end<=end or any(address%4 for address in (start,code_end,end)):
            raise ValueError('Invalid aligned ARM boundary')
        first=mapped_offset(start,config);last=mapped_offset(end-1,config)+1
        if last-first!=end-start:raise ValueError('Boundary crosses mappings')
        if row['code_bytes']!=code_end-start or row['literal_pool_bytes']!=end-code_end:
            raise ValueError('Boundary byte counts differ')
        callers=[]
        for text in row['callers']:
            address=int(text,16);offset=mapped_offset(address,config)
            word=struct.unpack_from('<I',payload,offset)[0]
            if word>>28==15 or word&0x0f000000!=0x0b000000 or branch_target(word,address)!=start:
                raise ValueError('Original caller does not BL to proposed entry')
            callers.append({'runtime_address':address,'word':hex(word),'target':start})
        if not callers:raise ValueError('No original direct caller')
        referenced=set();loads=[]
        for address in range(start,code_end,4):
            word=struct.unpack_from('<I',payload,first+address-start)[0]
            if word&0x0f7f0000==0x051f0000:
                target=address+8+(word&0xfff)*(1 if word&0x00800000 else -1)
                if code_end<=target<end:
                    if target%4:raise ValueError('Unaligned pool word')
                    referenced.add(target);loads.append({'instruction':address,'target':target,'word':hex(word)})
            if word&0x0e000000==0x0a000000 and code_end<=branch_target(word,address)<end:
                raise ValueError('Direct branch enters proposed literal pool')
        if referenced!=set(range(code_end,end,4)):
            raise ValueError('Trailing literal pool is not completely referenced by original word loads')
        terminal=struct.unpack_from('<I',payload,first+code_end-start-4)[0]
        if terminal&0x0ffffff0!=0x012fff10 or terminal>>28!=14:
            raise ValueError('Proposal does not end at unconditional BX return/tail transfer')
        evidence='original-boundary-proposal:'+row['name']
        claims.append(dict(start=first,end=first+code_end-start,classification='instruction',evidence=evidence))
        if code_end<end:claims.append(dict(start=first+code_end-start,end=last,classification='literal_pool',evidence=evidence))
        records.append({'name':row['name'],'runtime_start':start,'runtime_code_end':code_end,'runtime_end':end,
                        'payload_start':first,'payload_end':last,'original_sha256':hashlib.sha256(payload[first:last]).hexdigest(),
                        'direct_callers':callers,'pool_loads':loads,'terminal_word':hex(terminal),
                        'boundary_status':'bounded proposal independently rechecked; not exhaustive function discovery',
                        'original_authorship':'unknown'})
    return claims,records
