"use strict";
(() => {
 const $ = id => document.getElementById(id), arr = x => Array.isArray(x) ? x : [], n = x => Number.isFinite(x) ? x.toLocaleString() : "Unknown";
 const el = (tag, cls, text) => {const e=document.createElement(tag); e.className=cls||""; if(text!==undefined)e.textContent=text; return e;};
 let state, filter="all", error="", busy=false; const opened=new Set();
 const age = value => {const t=Date.parse(value); if(!Number.isFinite(t))return "Not reported"; const s=Math.max(0,(Date.now()-t)/1000); return s<60?"Just now":s<3600?Math.floor(s/60)+"m ago":s<86400?Math.floor(s/3600)+"h ago":Math.floor(s/86400)+"d ago";};
 const labels={pending:"Queued for review",review:"Awaiting review",reviewing:"In review",approved:"Ready to integrate",integrating:"Integrating",accepted:"Accepted",changes_requested:"Needs fixes",blocked:"Blocked",running:"Working",idle:"Idle",stale:"Signal stale",unknown:"Unknown",deferred:"Deferred"};
 function rowData(w){
  const sub=arr(state.pipeline?.submissions).filter(s=>s.lane===w.id).at(-1);
  const role=w.id.includes("reviewer")?"Reviewer":w.id.includes("integrator")?"Integrator":w.id.includes("coordinator")?"Coordinator":"Reconstruction";
  const raw=w.status||"unknown", status=sub&&!["running","working"].includes(raw)?sub.status:raw;
  const signal=Date.parse(w.updated_at), stale=(role!=="Reconstruction"||raw==="running")&&(!Number.isFinite(signal)||Date.now()-signal>180000);
  const category=stale||["blocked","changes_requested","failed","error","unknown","deferred"].includes(status)?"attention":["running","working"].includes(raw)?"active":"waiting";
  const task=sub&&role==="Reconstruction"?`${sub.module} / ${sub.commits?.length||0} commits / ${sub.source_tip?.slice(0,8)||""}`:w.task||"No task reported";
  return {w,sub,role,status,category,task,stale};
 }
 function renderAgents(){
  if(!state)return;
  const rows=arr(state.workers).map(rowData), query=$("search").value.toLowerCase().trim();
  const shown=rows.filter(r=>(filter==="all"||r.category===filter)&&[r.w.id,r.role,r.task,r.status].join(" ").toLowerCase().includes(query));
  const order={attention:0,active:1,waiting:2}; shown.sort((a,b)=>order[a.category]-order[b.category]||a.role.localeCompare(b.role)||a.w.id.localeCompare(b.w.id));
  $("agent-count").textContent=`${shown.length} / ${rows.length}`;
  $("agent-rows").replaceChildren(...shown.map(r=>{
   const d=el("details","agent"), summary=el("summary"), name=el("div"); d.open=opened.has(r.w.id);
   d.addEventListener("toggle",()=>{if(d.isConnected){if(d.open)opened.add(r.w.id);else opened.delete(r.w.id);}});
   name.append(el("span","name",r.w.id.replace(/^fleet_/,"")),el("span","role",r.role));
   const signal=el("span","signal",age(r.w.updated_at)); signal.title=r.w.updated_at||"No heartbeat recorded";
   const task=el("span","task",r.task); task.title=r.task;
   summary.append(name,el("span","stage "+r.category,r.stale?"Signal stale":labels[r.status]||r.status),task,signal);
   const info=el("div","agent-info");
   const fields=[["Task",r.w.task],["Model",r.w.model],["Worktree",r.w.worktree],["Process",r.w.pid],["Task activity",age(r.w.activity_at)],["Handed-off batches",r.w.completed_batches],["Review finding",r.sub?.error||r.sub?.review?.findings?.join("; ")||r.sub?.integration?.error]];
   for(const [label,value] of fields)if(value!==null&&value!==undefined&&value!==""){const p=el("p");p.append(el("strong","",label+": "),document.createTextNode(String(value)));info.append(p);}
   if(r.stale)info.append(el("p","","The last heartbeat is old; this is not proof that the process is still running."));
   d.append(summary,info);return d;
  }));
  if(!shown.length)$("agent-rows").append(el("p","empty","No agents match this view."));
 }
 function render(){
  const pc=state.pipeline?.counts||{}, fc=state.fleet?.counts||{};
  const metrics=[[fc.running,"Reconstructing"],[pc.pending,"Queued for review"],[pc.reviewing,"In review"],[pc.integrating,"Integrating"],[(pc.changes_requested||0)+(pc.blocked||0),"Needs attention"],[pc.accepted,"Accepted batches"]];
  $("overview").replaceChildren(...metrics.map(([v,k])=>{const e=el("div","metric");e.append(el("strong","",n(v)),el("span","",k));return e;}));
  $("mode").textContent=state.pipeline?.stopping?"Review pipeline draining":state.fleet?.stopping?"Reconstruction paused / Review pipeline active":"Agent and pipeline overview";
  renderAgents();
  const cov=state.coverage||{}, a=cov.arm9||{};
  const percent=(m,t)=>Number.isFinite(m)&&Number.isFinite(t)&&t>0?(100*m/t).toFixed(2)+"%":"Unknown";
  $("coverage-summary").textContent=percent(a.matched_functions,a.total_functions)+" ARM9 functions matched";
  $("coverage").replaceChildren(...[["Code bytes","code"],["Functions","functions"],["Data + BSS bytes","data"]].map(([label,k])=>{const d=el("div");d.append(el("small","",label),el("strong","",percent(a["matched_"+k],a["total_"+k])),el("small","",n(a["matched_"+k])+" / "+n(a["total_"+k])));return d;}));
  $("acceptance").textContent=`Accepted revision ${cov.accepted_revision||"unknown"} / ${age(cov.accepted_at)}`;
  $("arm7").replaceChildren(...[["source_functions","C functions"],["source_code_bytes","instruction bytes"],["source_literal_pool_bytes","literal bytes"],["source_data_bytes","initialized data bytes"],["source_bss_bytes","BSS bytes"],["reviewed_assembly_bytes","assembly bytes"],["binary_fallback_bytes","fallback bytes"]].map(([k,label])=>el("span","",`ARM7 ${label}: ${n(cov.arm7?.[k])}`)));
  const subs=arr(state.pipeline?.submissions); $("queue-count").textContent=`${subs.length} batches`;
  $("queue").replaceChildren(...subs.map(s=>{const d=el("div","queue-row"),info=el("div","",s.error||s.review?.findings?.join("; ")||s.integration?.error||`${s.commits?.length||0} commits`);info.append(el("small","",s.source_tip?.slice(0,12)||""));d.append(el("span","",s.lane),el("span","",labels[s.status]||s.status),info);return d;}));
  $("snapshot").textContent="Snapshot "+age(state.generated_at);health();
 }
 function health(){const stale=state&&(!Date.parse(state.generated_at)||Date.now()-Date.parse(state.generated_at)>30000);const messages=[error,stale?"Snapshot is stale. Displaying the last known state.":"",state?.pipeline?.stale?"Coordinator heartbeat is stale.":"",...arr(state?.warnings)].filter(Boolean);$("notice").hidden=!messages.length;$("notice").textContent=messages.join("\n");$("connection").textContent=error?"Disconnected":stale?"Stale state":state?"Live":"Connecting";$("refresh").textContent=state?"Updated "+age(state.generated_at):"Updates every 5 seconds";}
 async function poll(){if(busy)return;busy=true;const c=new AbortController(),timer=setTimeout(()=>c.abort(),8000);try{const r=await fetch("/api/state",{cache:"no-store",signal:c.signal});if(!r.ok)throw Error("HTTP "+r.status);const s=await r.json();if(!s||typeof s!=="object"||Array.isArray(s))throw Error("Invalid state");state=s;error="";render();}catch(e){error="Connection interrupted. Retrying every 5 seconds. "+e.message;health();}finally{clearTimeout(timer);busy=false;}}
 $("filters").addEventListener("click",e=>{const b=e.target.closest("button[data-filter]");if(!b)return;filter=b.dataset.filter;for(const x of $("filters").querySelectorAll("button"))x.setAttribute("aria-pressed",String(x===b));renderAgents();});
 $("search").addEventListener("input",renderAgents);poll();setInterval(poll,5000);
})();
