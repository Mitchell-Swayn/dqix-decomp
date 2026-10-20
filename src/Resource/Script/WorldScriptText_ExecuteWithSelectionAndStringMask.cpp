#include <globaldefs.h>
#include <Resource/Script.h>
// Original data: arm9/main @ 0x20f121c; symbol: data_020f121c.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 6400000040d508026500000048d508026600000050d508026700000094d508020000000000000000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108fc0; symbol: data_02108fc0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Context{unsigned pad[2],value;short first;unsigned short second;};struct Global{void* owner;Context* context;};extern "C" Global WorldScriptTextAllocateSelectedEntries_UnknownRoleZeroInitializedStorage;extern "C" Script::OpcodeLookupEntry WorldScriptTextExecuteWithSelectionAndStringMask_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x0208D860; symbol: func_0208d860; size: 0x8C.
extern "C" ARM void WorldScriptText_ExecuteWithSelectionAndStringMask(Context* context,void*owner,const void*code,unsigned len,unsigned value,short first,unsigned short second){Script script;if(owner&&code&&len){Global*g=&WorldScriptTextAllocateSelectedEntries_UnknownRoleZeroInitializedStorage;g->context=context;context->value=value;g->context->first=first;g->context->second=second;g->owner=owner;script.Initialize();script.SetOpcodeLookup(WorldScriptTextExecuteWithSelectionAndStringMask_UnknownRoleProcedureReferenceRecords);script.Load(code,len);script.Execute();}}
