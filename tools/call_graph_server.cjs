// Serve only the generated graph artifacts on the requested local interface.
const http=require('node:http'),fs=require('node:fs'),path=require('node:path');
const args=process.argv.slice(2),directory=args[0],host=args[1]||'127.0.0.1',port=Number(args[2]||8899);
if(!directory||!path.isAbsolute(directory)||!Number.isInteger(port)||port<1||port>65535)throw new Error('Usage: node call_graph_server.cjs ABSOLUTE_DIRECTORY [BIND_ADDRESS] [PORT]');
const files=new Map([['index.html','text/html; charset=utf-8'],['graph.json','application/json'],['decompilation-order.csv','text/csv; charset=utf-8'],['functions.sqlite','application/vnd.sqlite3']]);
http.createServer((req,res)=>{
  if(!['GET','HEAD'].includes(req.method)){res.writeHead(405);return res.end();}
  const name=new URL(req.url,'http://localhost').pathname.slice(1)||'index.html';
  if(!files.has(name)){res.writeHead(404);return res.end('Not found');}
  const file=path.join(directory,name);
  fs.stat(file,(error,stat)=>{
    if(error){res.writeHead(404);return res.end('Not generated yet');}
    res.setHeader('Content-Type',files.get(name));res.setHeader('Content-Length',stat.size);res.setHeader('Cache-Control','no-cache');
    if(name.endsWith('.sqlite'))res.setHeader('Content-Disposition','attachment; filename="dqix-functions.sqlite"');
    if(req.method==='HEAD')return res.end();
    const stream=fs.createReadStream(file);res.on('close',()=>stream.destroy());stream.on('error',()=>res.destroy());stream.pipe(res);
  });
}).listen(port,host,()=>console.log(`DQIX call graph: http://${host}:${port}/`));
