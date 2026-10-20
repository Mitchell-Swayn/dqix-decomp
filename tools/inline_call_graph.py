"""Adapt the offline viewer into a compressed, conversation-sized fragment."""
import base64
import gzip
import json
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]
source = (ROOT/'tools/call_graph_viewer.html').read_text(encoding='utf-8')
graph = json.loads((ROOT/'build/call-graph/graph.json').read_text())
ids = {n['id']:i for i,n in enumerate(graph['nodes'])}
compact = dict(n=[[n['id'],n['name'],n['module'],n['address'],n['size'],n['mode']] for n in graph['nodes']],
               e=[[ids[e['source']],ids[e['target']],e['kind'],e['ambiguous']] for e in graph['edges']],
               i=[[ids[s['source']],s['site'],s['instruction']] for s in graph['indirect']],
               l=graph['metadata']['limitations'], m=graph['metadata']['module_counts'])
encoded = base64.b64encode(gzip.compress(json.dumps(compact,separators=(',',':')).encode())).decode()
style = '''<style>
#dqix-call-network{color:var(--foreground);width:100%}
#dqix-call-network .cg-layout{display:grid;grid-template-columns:minmax(180px,230px) minmax(0,1fr);gap:16px}
#dqix-call-network aside{min-width:0;overflow-wrap:anywhere}
#dqix-call-network #results{display:flex;flex-wrap:wrap;gap:4px}
#dqix-call-network #neighbors{display:flex;flex-direction:column;gap:4px}
#dqix-call-network #stage{min-width:0;position:relative;height:560px}
#dqix-call-network canvas{width:100%;height:100%;touch-action:none}
#dqix-call-network #status{overflow-wrap:anywhere;grid-column:1/-1}
#dqix-call-network #counts,#dqix-call-network .legend{margin-bottom:8px}
#dqix-call-network .row{display:flex;flex-wrap:wrap;gap:8px;margin:8px 0}
#dqix-call-network .result{overflow-wrap:anywhere;text-align:left;white-space:normal}
@media(max-width:550px){#dqix-call-network .cg-layout{display:flex;flex-direction:column}#dqix-call-network #stage{height:460px}#dqix-call-network #neighbors{display:grid;grid-template-columns:repeat(2,minmax(0,1fr))}}
</style>'''
markup = source[source.index('<header>'):source.index('<script>')]
markup = markup.replace('<main>','<div class="cg-layout">').replace('</main>','</div>')
markup = markup.replace('<input ', '<input class="form-control" ').replace('<select ', '<select class="form-select" ')
markup = markup.replace('<button ', '<button class="btn" type="button" ')
markup = markup.replace('<label ', '<label class="form-label" ')
markup = markup.replace('<h1>','<h3>').replace('</h1>','</h3>')
markup = markup.replace('<div id="counts">','<div class="text-small text-muted" id="counts">')
markup = markup.replace('<div class="legend">','<div class="text-small text-muted">')
markup = markup.replace('<canvas id="network"','<canvas class="cursor-interaction" role="img" id="network"')
markup = markup.replace('<div id="status"></div></section>', '</section><div class="text-small text-muted" aria-live="polite" id="status"></div>')
markup = markup.replace('Arrow: caller → callee · blue: callers · amber: selected · green: callees', 'Arrow: caller → callee · selected function is the central node')
js = source[source.index('<script>')+8:source.index('</script>')]
js = js.replace('const graph=/*GRAPH_DATA*/;', '''const root=document.getElementById('dqix-call-network');
const packed=Uint8Array.from(atob('PACKED_DATA'),c=>c.charCodeAt(0));
const reader=new Blob([packed]).stream().pipeThrough(new DecompressionStream('gzip')).getReader();
const parts=[];let total=0;while(true){const {value,done}=await reader.read();if(done)break;parts.push(value);total+=value.length}
const bytes=new Uint8Array(total);let cursor=0;for(const part of parts){bytes.set(part,cursor);cursor+=part.length}
const c=JSON.parse(new TextDecoder().decode(bytes));
const graph={nodes:c.n.map(n=>({id:n[0],name:n[1],module:n[2],address:n[3],size:n[4],mode:n[5]})),edges:c.e.map(e=>({source:c.n[e[0]][0],target:c.n[e[1]][0],kind:e[2],ambiguous:e[3],sites:[]})),indirect:c.i.map(i=>({source:c.n[i[0]][0],site:i[1],instruction:i[2]})),unresolved:[],metadata:{limitations:c.l,module_counts:c.m}};
'''.replace('PACKED_DATA',encoded))
js = js.replace('document.getElementById(id)','root.querySelector("#"+id)')
js = js.replace("b.className='result'", "b.className='btn btn-ghost result'")
js = js.replace("p.className='meta'", "p.className='text-small text-muted'")
js = js.replace("b.title='Sites: '+e.sites.map(hex).join(', ');",'')
js = js.replace('hits.slice(0,30)','hits.slice(0,8)').replace('hits.length>30','hits.length>8')
js = js.replace("canvas.title=hit?nodes.get(hit).name+' · '+nodes.get(hit).module+' · '+hex(nodes.get(hit).address):''", "canvas.setAttribute('aria-label',hit?nodes.get(hit).name+' · '+nodes.get(hit).module:'Directed call graph')")
js = js.replace("ctx.clearRect(0,0,width,height);", "ctx.clearRect(0,0,width,height);const color=(token)=>getComputedStyle(root).getPropertyValue(token).trim();")
for literal,token in {'#b990d2':'--viz-series-4','#66caaa':'--viz-series-2','#71adf2':'--viz-series-1','#536277':'--border','#ffc46b':'--viz-series-3','#e3eaf4':'--foreground'}.items():
    js = js.replace("'"+literal+"'", "color('"+token+"')")
js = js.replace("h.textContent=name+' ('+es.length+')';", "h.textContent=name+' ('+es.length+')';")
js = js.replace('function select(id)', 'function select(id,persist=true)')
js = js.replace("selected=id;overview=false;", "selected=id;overview=false;if(persist&&window.openai?.setWidgetState)window.openai.setWidgetState({modelContent:{selectedFunction:nodes.get(id).name,module:nodes.get(id).module},privateContent:{id}}).catch(()=>{});")
js = js.replace("results();select(graph.nodes.find(n=>n.name.includes('InitRandom')).id);", "results();const saved=window.openai?.widgetState?.privateContent?.id;select(nodes.has(saved)?saved:graph.nodes.find(n=>n.name.includes('InitRandom')).id,false);window.addEventListener('openai:set_globals',e=>{const id=e.detail?.globals?.widgetState?.privateContent?.id;if(nodes.has(id)&&id!==selected)select(id,false)});")
fragment = style+'\n<div id="dqix-call-network">\n'+markup+'\n</div>\n<script>\n(async()=>{\n'+js+'\n})().catch(error=>{document.getElementById("dqix-call-network").querySelector("#status").textContent=error.message});\n</script>\n'
assert len(fragment.encode())<1_000_000
dest=ROOT/'build/call-graph/dqix-call-network.html'
dest.write_text(fragment,encoding='utf-8')
print(f'{dest}: {len(fragment.encode())} bytes')
