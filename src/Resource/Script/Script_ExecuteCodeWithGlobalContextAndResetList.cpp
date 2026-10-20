#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x20f1444; symbol: data_020f1444.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000784d090265000000804d090266000000884d090267000000d851090268000000b05409020000000000000000.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109404; symbol: data_02109404.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage[];extern "C" Script::OpcodeLookupEntry QuestExecuteOrderPayloadScript_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x0209562C; symbol: func_0209562c; size: 0x8C.
extern "C" void Script_ExecuteCodeWithGlobalContextAndResetList(unsigned char* p,void* context,const void* code,unsigned size,unsigned short a,unsigned b,unsigned c){Script s;if(!context||!code||!size)return;*(unsigned short*)(ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage+8)=a;ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage[3]=b;ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage[4]=c;*(void**)(ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage+12)=context;*(unsigned*)(p+160)=0;ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage[0]=0;s.Initialize();s.SetOpcodeLookup(QuestExecuteOrderPayloadScript_UnknownRoleProcedureReferenceRecords);s.Load(code,size);s.Execute();}
