#!/usr/bin/env python3
"""Generate advisory SDK structural candidates from pinned local reference sources.

Inputs: build/sdk-identification/*-index.json and referenced source directories.
This does not change symbols, compiler selection, reconstruction eligibility, or build inputs.
See docs/SDK_IDENTIFICATION.md for limitations and source provenance.
"""
import re,json,sqlite3,pathlib,hashlib,collections,difflib
ROOT=pathlib.Path(__file__).resolve().parents[1]; OUT=ROOT/'build/sdk-identification'
# Explicit opt-in fetching, pinned to the reviewed repository revisions.
import sys, urllib.request, concurrent.futures
if '--fetch' in sys.argv:
    OUT.mkdir(parents=True, exist_ok=True)
    packages=[('pret/pokeheartgold','14c48938174ec92563afc6d03de5fa162f4cfdce','reference','reference-index.json'),('pret/pokediamond','caba1031233657d89f3c35079e664551a07cd72f','reference-diamond','diamond-index.json'),('pret/pokediamond','b623abef1b4dfe204ca50aab42447ac00c134290','diamond-c','diamond-c-index.json')]
    for repo,commit,directory,index in packages:
        tree=json.load(urllib.request.urlopen(f'https://api.github.com/repos/{repo}/git/trees/{commit}?recursive=1',timeout=30))
        paths=[]
        for item in tree['tree']:
            path=item['path']
            if directory=='reference': include=path.startswith('lib/NitroSDK/') and path.endswith(('.s','.c'))
            elif directory=='reference-diamond': include=bool(re.match(r'arm[79]/asm/(OS|MI|GX|G2|G3|FX|FS|CARD|CP|DC|IC|SND|SPI|RTC|TP|PM|PAD|CTRDG|MB|PXI|WVR|WM|WBT|WFS|EXI|SVC|DGT|MATH)_.*\.s$',path))
            else: include=(path.startswith('arm9/lib/NitroSDK/') or path.startswith('arm7/lib/src/')) and path.endswith('.c')
            if include: paths.append(path)
        def download(path):
            dest=OUT/directory/path;dest.parent.mkdir(parents=True,exist_ok=True)
            dest.write_bytes(urllib.request.urlopen(f'https://raw.githubusercontent.com/{repo}/{commit}/{path}',timeout=30).read())
        with concurrent.futures.ThreadPoolExecutor(max_workers=8) as pool: list(pool.map(download,paths))
        (OUT/index).write_text(json.dumps({'repository':repo,'commit':commit,'paths':paths},indent=2))
def norm(line):
 line=line.split(';')[0].split('//')[0].strip().lower()
 line=re.sub(r'^([0-9a-f]{8}):\s*','',line)
 if not line or ':' in line or line.startswith(('.', '#')):return None
 parts=line.split(None,1);op=parts[0];args=parts[1] if len(parts)>1 else ''
 if not re.match(r'^[a-z][a-z0-9]*$',op):return None
 if op in ['arm_func_start','arm_func_end','thumb_func_start','thumb_func_end']:return None
 args=re.sub(r'\b(ip|fp|sl|sb)\b',lambda m:{'ip':'r12','fp':'r11','sl':'r10','sb':'r9'}[m[0]],args)
 args=re.sub(r'r(\d+)\s*-\s*r(\d+)',lambda m:','.join('r'+str(i) for i in range(int(m[1]),int(m[2])+1)),args)
 args=re.sub(r'#?(0x[0-9a-f]+|\b\d+\b)',lambda m:'#'+str(int(m[1],0) if m[1].startswith('0x') else int(m[1])),args)
 args=re.sub(r'\[([^\]]+),\s*#0\]',r'[\1]',args)
 args=re.sub(r'\s+','',args)
 if op=='stmdb' and args.startswith('sp!,'):op='push';args=args[4:]
 if op=='ldmia' and args.startswith('sp!,'):op='pop';args=args[4:]
 if op=='mov' and re.search(r',(lsl|lsr|asr|ror)#',args):
  a,b,c=args.split(',');m=re.match(r'(lsl|lsr|asr|ror)(#.*)',c);op=m[1];args=a+','+b+','+m[2]
 if re.match(r'^b(l|lx)?(eq|ne|cs|cc|mi|pl|vs|vc|hi|ls|ge|lt|gt|le|hs|lo)?$',op):args='@branch'
 if op.startswith('ldr') and (('[pc' in args) or re.search(r',(?:_0[12][0-9a-f]+|=)',args)):args=args.split(',')[0]+',@literal'
 return op+' '+args
refs=[]
for sub,index in [('reference','reference-index.json'),('reference-diamond','diamond-index.json')]:
 meta=json.loads((OUT/index).read_text())
 for rel in meta['paths']:
  p=OUT/sub/rel;s=p.read_text(errors='replace');sha=hashlib.sha256(p.read_bytes()).hexdigest()
  blocks=[]
  if rel.endswith('.s'):
   hits=list(re.finditer(r'^\s*(?:arm|thumb)_func_start\s+(\w+)',s,re.M))
   for i,h in enumerate(hits):blocks.append((h[1],s[h.end():hits[i+1].start() if i+1<len(hits) else len(s)]))
  else:
   for h in re.finditer(r'\basm\s+[^;{}]*?\b(\w+)\s*\([^;{}]*\)\s*\{',s):
    j=h.end();depth=1
    while j<len(s) and depth:
     depth+=(s[j]=='{')-(s[j]=='}');j+=1
    blocks.append((h[1],s[h.end():j-1]))
  for name,body in blocks:
   seq=[n for line in body.splitlines() if (n:=norm(line))]
   if len(seq)<4:continue
   refs.append({'name':name,'path':rel,'repository':meta['repository'],'commit':meta['commit'],'source_sha256':sha,'sequence':seq})
# Deduplicate identical name/signature across sources.
uniq={}
for r in refs:uniq.setdefault((r['name'],tuple(r['sequence'])),r)
refs=list(uniq.values());grams=collections.defaultdict(set)
for i,r in enumerate(refs):
 for j in range(len(r['sequence'])-3):grams[tuple(r['sequence'][j:j+4])].add(i)
conn=sqlite3.connect(ROOT/'inventory/functions.sqlite');conn.row_factory=sqlite3.Row;rows=[]
for f in conn.execute('select id,module_id,name,address,size,assembly,original_sha256 from functions'):
 seq=[n for l in f['assembly'].splitlines() if (n:=norm(l))]
 if len(seq)<4:continue
 candidates=collections.Counter()
 for j in range(len(seq)-3):candidates.update(grams.get(tuple(seq[j:j+4]),()))
 scores=[]
 for i,n in candidates.most_common(15):
  ref=refs[i];rs=ref['sequence']
  if min(len(rs),len(seq))/max(len(rs),len(seq))<.7:continue
  score=difflib.SequenceMatcher(None,seq,rs,autojunk=False).ratio()
  if score>=.85:scores.append((score,ref))
 if not scores:continue
 scores.sort(key=lambda t:t[0],reverse=True);best=scores[0][0]
 choices=[r for score,r in scores if score>=best-.025]
 row={k:f[k] for k in ['id','module_id','name','size','original_sha256']};row['address']=f'0x{f["address"]:08X}';row['instruction_count']=len(seq);row['similarity']=round(best,6)
 row['status']='structural_candidate';row['ambiguous']=len(set(r['name'] for r in choices))>1
 row['sdk_candidates']=[{k:r[k] for k in ['name','path','repository','commit','source_sha256']} for r in choices[:6]]
 row['limitations']='Branch destinations and PC-relative literal locations normalized; not byte matching or proof of library origin.'
 rows.append(row)
(OUT/'scan-results.json').write_text(json.dumps({'reference_functions':len(refs),'matches':rows},indent=2))
print('references',len(refs),'candidate functions',len(rows),'unique identities',len(set(x['sdk_candidates'][0]['name'] for x in rows)))
print(collections.Counter(x['module_id'] for x in rows));print(collections.Counter(x['sdk_candidates'][0]['name'].split('_')[0] for x in rows))
# Map structural identities to real definitions, excluding prototypes.
cmeta=json.loads((OUT/'diamond-c-index.json').read_text());definitions=collections.defaultdict(list)
pattern=re.compile(r'^[ \t]*(?:(?:static|asm|inline|const|volatile|extern)\s+)*[\w* \t]+\b(\w+)\s*\([^;{}]*\)\s*\{',re.M)
for rel in cmeta['paths']:
 p=OUT/'diamond-c'/rel;text=p.read_text(errors='replace')
 for m in pattern.finditer(text):
  name=m[1]
  if name in {'if','while','for','switch'}:continue
  line=text.count('\n',0,m.start())+1
  definitions[name].append({'repository':cmeta['repository'],'commit':cmeta['commit'],'path':rel,'line':line,'url':f'https://github.com/{cmeta["repository"]}/blob/{cmeta["commit"]}/{rel}#L{line}','source_sha256':hashlib.sha256(p.read_bytes()).hexdigest(),'source_form':'inline_assembly' if re.search(r'\basm\b',m[0]) else 'c'})
for row in rows:
 for ref in row['sdk_candidates']:
  ref['reconstructed_definitions']=sorted(definitions.get(ref['name'],[]), key=lambda d: not d['path'].startswith('arm7/' if row['module_id'].startswith('arm7/') else 'arm9/'))
  ref['assembly_url']=f'https://github.com/{ref["repository"]}/blob/{ref["commit"]}/{ref["path"]}'
 row['confidence']='strong_structural_candidate' if row['similarity']==1 and row['instruction_count']>=8 and not row['ambiguous'] else 'candidate_needs_review'
# Add independently established origins; structural comparisons alone never receive this label.
verified=[{'id':'arm9/main:020c7b40','sdk_name':'OS_Sleep','evidence':'build/sol-one-three-20261012/project/build/sleep-resolved-raw.json','description':'168-byte candidate equals original at resolved DQIX addresses; historical compiler1.2/sp2p3.'},{'id':'arm9/main:020ca594','sdk_name':'MI_CpuFill8','evidence':'config/usa/arm9/runtime_support.json','description':'Accepted community SDK reconstruction with instruction and raw-byte provenance.'}]
accepted_policy=json.loads((ROOT/'config/usa/arm9/runtime_support.json').read_text())
for accepted in accepted_policy['functions']:
 if accepted.get('evidence_class')=='sdk_reconstruction':
  fid=accepted['module']+':'+format(int(accepted['address'],0),'08x')
  if not any(v['id']==fid for v in verified): verified.append({'id':fid,'sdk_name':accepted['name'],'evidence':'config/usa/arm9/runtime_support.json','description':'Accepted community SDK inline assembly with exact object/raw comparison and full-ROM integration.'})
for v in verified:
 row=next((r for r in rows if r['id']==v['id']),None)
 if row:row['confidence']='verified_origin';row['verification']=v
summary={'candidate_functions':len(rows),'verified_origins':sum(r['confidence']=='verified_origin' for r in rows),'strong_structural_candidates':sum(r['confidence']=='strong_structural_candidate' for r in rows),'review_candidates':sum(r['confidence']=='candidate_needs_review' for r in rows),'mapped_to_c_definition':sum(any(d['source_form']=='c' for ref in r['sdk_candidates'] for d in ref['reconstructed_definitions']) for r in rows),'mapped_to_inline_assembly_definition':sum(any(d['source_form']=='inline_assembly' for ref in r['sdk_candidates'] for d in ref['reconstructed_definitions']) for r in rows)}
manifest={'schema_version':1,'classification':'advisory_sdk_origin_inventory','complete_sdk_inventory':False,'changes_build':False,'normalization':'Register aliases and immediate spelling normalized; branch destinations and PC-relative literal addresses erased. Embedded literals, call identities, register allocation variants, and SDK-version differences require review. Generic small routines may be false positives. Similarity is not a byte-match percentage.','reference_function_variants':len(refs),'summary':summary,'functions':rows}
(ROOT/'config/usa/sdk_function_candidates.json').write_text(json.dumps(manifest,indent=2)+'\n')
lines=['# SDK function identification','','This is an advisory origin inventory, not a build or compiler policy. It does not claim every SDK function has been identified. Compiler runtime/MSL and third-party middleware are separate categories.','','## Results','',f"{len(rows)} structural candidates: {summary['verified_origins']} verified origins, {summary['strong_structural_candidates']} strong structural candidates, {summary['review_candidates']} requiring further review.",f"{summary['mapped_to_c_definition']} candidates have a corresponding reconstructed C definition. Some also have assembly definitions in another processor/version.",'','## Evidence and limitations','','Reference assembly comes from pinned pret/pokediamond and pret/pokeheartgold reconstructions. Branch destinations and PC-relative literal addresses are normalized, so even a100% structural similarity is not byte matching. Small or ambiguous routines require manual review. Do not rename functions or select compilers from this file automatically. SDK routines can be originally C or originally assembly; origin alone does not justify assembly acceptance.','','Verified origins include OS_Sleep (168-byte C++ reconstruction, integrated using its historical compiler profile) and accepted SDK assembly entries in runtime_support.json. Each verified record retains its proof; structural candidates remain unaccepted.','','Full machine-readable evidence: [sdk_function_candidates.json](../config/usa/sdk_function_candidates.json).','','## Mapping','', '| DQIX module/address | Current inventory name | SDK identity | Structural similarity | Evidence | Pokémon Diamond definition |','|---|---|---|---:|---|---|']
for r in sorted(rows,key=lambda r:(r['module_id'],r['address'])):
 names=', '.join(dict.fromkeys(x['name'] for x in r['sdk_candidates']))
 ds=[d for ref in r['sdk_candidates'] for d in ref['reconstructed_definitions']]
 ds=[d for d in ds if d['source_form']=='c'] or ds
 link=f"[{ds[0]['path'].split('/')[-1]}:{ds[0]['line']}]({ds[0]['url']})" if ds else 'Not reconstructed/found in scanned source'
 lines.append(f"| {r['module_id']} `{r['address']}` | `{r['name']}` | {names} | {r['similarity']*100:.1f}% | {r['confidence']} | {link} |")
lines+=['','## Reproduce','','Run `python3 tools/identify_sdk_functions.py --fetch` to download the pinned reference trees and regenerate the inventory. Subsequent runs can omit `--fetch` to reuse the local inputs. Index files bind repository,40-character commit and relative paths; output records every referenced source SHA-256. Downloaded community sources remain ignored development evidence, not compiled project inputs.','','Reference trees:']
for fn in ['reference-index.json','diamond-index.json','diamond-c-index.json']:
 d=json.loads((OUT/fn).read_text());lines.append(f"- `{d['repository']}@{d['commit']}` ({len(d['paths'])} source files; `{fn}`).")
(ROOT/'docs/SDK_IDENTIFICATION.md').write_text('\n'.join(lines)+'\n')
print('Published advisory inventory:',json.dumps(summary))
