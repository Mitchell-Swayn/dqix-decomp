"""Authenticate appended compiler helpers against their vendor package and ELF bytes."""
import hashlib
import io
import re
import struct
import tarfile


def archive_member(data, wanted):
    if data[:8] != b'!<arch>\n':
        raise ValueError('Invalid vendor archive')
    pos, names, found = 8, b'', []
    while pos + 60 <= len(data):
        head = data[pos:pos+60]
        if head[58:60] != b'`\n':
            raise ValueError('Invalid archive member header')
        size = int(head[48:58]); name = head[:16].decode().strip()
        body = data[pos+60:pos+60+size]
        if len(body) != size:
            raise ValueError('Truncated archive member')
        pos += 60 + size + size % 2
        if name == '//':
            names = body; continue
        if name in ('/', '/SYM64/'):
            continue
        if name.startswith('/') and name[1:].isdigit():
            name = names[int(name[1:]):].split(b'/\n')[0].decode()
        elif name.startswith('#1/'):
            count = int(name[3:]); name = body[:count].decode().rstrip('\0'); body = body[count:]
        else:
            name = name.rstrip('/')
        if name == wanted:
            found.append(body)
    if len(found) != 1:
        raise ValueError('Vendor member missing or duplicated')
    return found[0]


def resolved_function(data, name, size, bindings):
    """Resolve only explicit ABS32 data references; refuse all other relocation kinds."""
    if data[:6] != b'\x7fELF\x01\x01':
        raise ValueError('Vendor proof requires ELF32 little endian')
    off = struct.unpack_from('<I', data, 32)[0]
    stride, count = struct.unpack_from('<HH', data, 46)
    sections = [struct.unpack_from('<10I', data, off+i*stride) for i in range(count)]
    def content(s):
        value = data[s[4]:s[4]+s[5]]
        if len(value) != s[5]:
            raise ValueError('Truncated ELF section')
        return value
    tables, found, files = {}, [], []
    for index, s in enumerate(sections):
        if s[1] != 2:
            continue
        strings = content(sections[s[6]]); symbols = []
        for pos in range(0, s[5], s[9]):
            n, value, extent, info, other, section = struct.unpack_from('<IIIBBH', content(s), pos)
            label = strings[n:].split(b'\0', 1)[0].decode()
            symbols.append((label, value, extent, info, section))
            if info & 15 == 4:
                files.append(label)
            if label == name and section and info >> 4:
                found.append(symbols[-1])
        tables[index] = symbols
    if len(found) != 1:
        raise ValueError('Vendor public symbol missing or duplicated')
    _, value, extent, _, idx = found[0]; section = sections[idx]
    start = (value & ~1)-section[3]
    # Unsized vendor assembly symbols must occupy the remaining section exactly.
    if (extent and extent != size) or (not extent and section[5]-start != size):
        raise ValueError('Vendor full function extent differs')
    raw = bytearray(content(section)[start:start+size]); used = []
    if len(raw) != size:
        raise ValueError('Function exceeds ELF section')
    for s in sections:
        if s[1] not in (4, 9) or s[7] != idx:
            continue
        for pos in range(0, s[5], s[9]):
            offset, info = struct.unpack_from('<II', content(s), pos)
            if not start <= offset < start+size:
                continue
            if info & 255 != 2 or offset+4 > start+size:
                raise ValueError('Unsupported vendor-proof relocation')
            symbol = tables[s[6]][info >> 8][0]
            if symbol not in bindings:
                raise ValueError('Unbound vendor relocation')
            addend = struct.unpack_from('<i', content(s), pos+8)[0] if s[1] == 4 else struct.unpack_from('<I', raw, offset-start)[0]
            struct.pack_into('<I', raw, offset-start, (bindings[symbol]+addend) & 0xffffffff)
            used.append([offset-start, symbol, 2])
    return bytes(raw), files, used


def validate_compiler_row(main, worker, row, function):
    from runtime_support import _bound, evidence_class, _sha256
    evidence = row.get('evidence', {})
    if (evidence_class(row) != 'compiler_runtime' or row['classification'] != 'runtime_assembly' or
            row.get('assembly_form') != 'codewarrior_inline' or row.get('c_reconstruction_eligible') is not False or
            not row['source'].startswith('src/RuntimeSupport/') or not row['source'].endswith('.cpp') or
            evidence.get('origin') != 'vendor_archive' or evidence.get('vendor_archive_match') is not True or
            evidence.get('exact_resolved_match') is not True):
        raise ValueError('Compiler append requires authenticated vendor inline assembly')
    auth = evidence['authentication']
    package = _bound(worker, auth, 'package', 'package_sha256')
    if auth['package_sha256'] != evidence['package_sha256'] or not evidence.get('package_url'):
        raise ValueError('Vendor package provenance differs')
    with tarfile.open(package) as archive:
        members = [m for m in archive.getmembers() if m.isfile() and m.name == auth['archive_member']]
        if len(members) != 1 or not auth['archive_member'].endswith('/sdk/'+evidence['library']):
            raise ValueError('Vendor package archive missing or ambiguous')
        library = archive.extractfile(members[0]).read()
    if hashlib.sha256(library).hexdigest() != evidence['archive_sha256']:
        raise ValueError('Vendor archive hash differs')
    vendor = archive_member(library, evidence['object'])
    if hashlib.sha256(vendor).hexdigest() != evidence['object_sha256']:
        raise ValueError('Vendor object hash differs')
    import pathlib
    symbols = dict(re.findall(r'(?m)^(\S+).* addr:0x([0-9a-fA-F]+)', (pathlib.Path(main)/'config/usa/arm9/symbols.txt').read_text()))
    bindings = evidence.get('relocation_bindings', {})
    def addresses(which):
        result = {}
        for label, item in bindings.items():
            target = item['target_symbol']; address = int(item['address'], 0)
            if target not in symbols or int(symbols[target], 16) != address:
                raise ValueError('Runtime relocation does not match owning symbols')
            result[label if which == 'vendor' else target] = address
        return result
    original = row['original_sha256']; size = row['size']
    raw, files, relocs = resolved_function(vendor, evidence['vendor_symbol'], size, addresses('vendor'))
    if (hashlib.sha256(raw).hexdigest() != original or files != evidence['source_files'] or
            relocs != evidence['relocations'] or evidence['vendor_symbol'] not in evidence['symbols']):
        raise ValueError('Vendor full resolved bytes or provenance differ')
    fresh = evidence['fresh_object_check']
    candidate = _bound(worker, fresh, 'candidate_source', 'candidate_source_sha256')
    obj = _bound(worker, fresh, 'candidate_object', 'candidate_object_sha256')
    result = __import__('json').loads(_bound(worker, fresh, 'result', 'result_sha256').read_text())
    resolved, _, candidate_relocs = resolved_function(obj.read_bytes(), row['name'], size, addresses('candidate'))
    if (hashlib.sha256(resolved).hexdigest() != original or
            fresh['candidate_source_sha256'] != row['source_sha256'] or
            result.get('status') != 'compared' or result.get('object_match') is not True or
            result.get('mismatches') != 0 or result.get('unit') != row['source'][:-4] or
            result.get('rom_acceptance') is not False or result.get('raw_match') is False):
        raise ValueError('Compiler fresh object/source proof differs')
