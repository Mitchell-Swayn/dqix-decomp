const fs=require('fs'),vm=require('vm'),assert=require('assert');
const html=fs.readFileSync('build/progress/treemap.html','utf8');
const data=html.match(/<script id="progress-data" type="application\/json">([\s\S]*?)<\/script>/)[1];
const expected=JSON.parse(data);
const script=html.match(/<script>\s*([\s\S]*?)<\/script>/)[1];
const elements=new Map(),ops=[];
const ctx={globalAlpha:1,fillStyle:'',font:'',fillRect(x,y,w,h){assert([x,y,w,h].every(Number.isFinite));assert(w>=0&&h>=0);ops.push({type:'rect',x,y,w,h,color:this.fillStyle,alpha:this.globalAlpha})},fillText(text,x,y){ops.push({type:'text',text,x,y,color:this.fillStyle})},save(){},restore(){},beginPath(){},rect(){},clip(){},scale(){},strokeRect(){}};
function element(id){if(!elements.has(id))elements.set(id,{textContent:id==='progress-data'?data:'',innerHTML:'',value:'',hidden:false,clientWidth:1400,clientHeight:640,style:{},dataset:{},listeners:{},setAttribute(){},addEventListener(k,f){this.listeners[k]=f},getContext(){return ctx},getBoundingClientRect(){return {left:0,top:0}}});return elements.get(id)}
const sandbox={document:{getElementById:element},window:{devicePixelRatio:1,innerWidth:1400,innerHeight:1000},ResizeObserver:class{observe(){}},console};
vm.createContext(sandbox);vm.runInContext(script,sandbox);
function run(code){return vm.runInContext(code,sandbox)}
assert.equal(run('new Set(rects.map(r=>r.u)).size'),run('D.units.filter(u=>weight(u)>0).length'));
assert.equal(run('rects.filter(r=>r.f).length'),run('D.units.filter(u=>weight(u)>0).reduce((s,u)=>s+u.functions.filter(f=>f.size>0).length,0)'));
assert.equal(run('activeUnits().reduce((s,u)=>s+weight(u),0)'),expected.measures.total_code);
const base=ops.slice();
element('tiles').value='units';element('tiles').onchange();assert.equal(run('rects.length'),run('D.units.filter(u=>weight(u)>0).length'));
element('tiles').value='functions';element('tiles').onchange();
// Area preservation and nonoverlap for the actual squarifier, including narrow layouts.
for(let size of [[1400,640],[320,480],[1,1]]){
 const rs=run(`layout(Array.from({length:609},(_,i)=>({value:i+1})),0,0,${size[0]},${size[1]})`);
 assert(Math.abs(rs.reduce((s,r)=>s+r.w*r.h,0)-size[0]*size[1])<1e-5);
 for(let i=0;i<rs.length;i++)for(let j=i+1;j<rs.length;j++)assert(Math.min(rs[i].x+rs[i].w,rs[j].x+rs[j].w)-Math.max(rs[i].x,rs[j].x)<1e-7||Math.min(rs[i].y+rs[i].h,rs[j].y+rs[j].h)-Math.max(rs[i].y,rs[j].y)<1e-7);
}
element('search').value='GameState';element('search').oninput();assert.equal(run('activeUnits().reduce((s,u)=>s+weight(u),0)'),expected.measures.total_code);
element('module').value='ov000';element('module').onchange();assert.equal(run('module'),'ov000');element('back').onclick();assert.equal(run('module'),'all');
run('select(D.units.find(u=>u.functions.length))');assert.equal(element('functions-panel').hidden,false);
element('arm7').onclick();assert.equal(run('activeUnits().reduce((s,u)=>s+weight(u),0)'),expected.arm7_measures.payload_bytes);
element('metric').value='bss';element('metric').onchange();assert.equal(run('activeUnits().reduce((s,u)=>s+weight(u),0)'),expected.arm7_measures.total_bss_bytes);
element('arm9').onclick();element('metric').value='data';element('metric').onchange();assert.equal(run('activeUnits().reduce((s,u)=>s+weight(u),0)'),expected.measures.total_data);
element('metric').value='functions';element('metric').onchange();assert.equal(run('activeUnits().reduce((s,u)=>s+weight(u),0)'),expected.measures.total_functions);
element('map').clientWidth=320;run('draw()');
fs.writeFileSync('build/progress/draw-commands.json',JSON.stringify(base));
console.log('Interaction checks passed: layout areas/nonoverlap, all views, module navigation, selection, highlight invariance, 320px layout.');
