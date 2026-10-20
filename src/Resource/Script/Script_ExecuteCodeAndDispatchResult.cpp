#include <globaldefs.h>
#include <Resource/Script.h>
// Original data: arm9/main @ 0x20f05bc; symbol: data_020f05bc.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000bcf9050265000000c4f9050201000000ccf905020000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Owner {char pad[0x480];void* a;unsigned b,c,d;};struct Result {char pad[12];unsigned value;char unknown[0x24];};extern "C" Script::OpcodeLookupEntry ScriptExecuteCodeAndDispatchResult_UnknownRoleProcedureReferenceRecords[];extern "C" int Script_ExecuteFirstSatisfiedTriggerGroup(Owner*,int,Result*);extern "C" void Script_DispatchResultCommandsToWorld(Result*);
// Original: arm9/main @ 0x02064574; symbol: func_02064574; size: 0xA8.
extern "C" void Script_ExecuteCodeAndDispatchResult(Owner* self,void* a,const void* code,unsigned length,unsigned b,unsigned c,unsigned d) {if(a && code && length){self->a=a;self->b=b;self->c=c;self->d=d;Result result;Script script;script.Initialize();script.SetOpcodeLookup(ScriptExecuteCodeAndDispatchResult_UnknownRoleProcedureReferenceRecords);script.Load(code,length);script.Execute();result.value=b;if(Script_ExecuteFirstSatisfiedTriggerGroup(self,20,&result))Script_DispatchResultCommandsToWorld(&result);}}
