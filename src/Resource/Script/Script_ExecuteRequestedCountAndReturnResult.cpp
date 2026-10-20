#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20f13d8; symbol: data_020f13d8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f13fc; symbol: data_020f13fc.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000784d090265000000804d090266000000645309020000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109404; symbol: data_02109404.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" volatile unsigned char ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage[];extern "C" volatile unsigned short QuestExecuteOrderPayloadScript_UnknownRoleInitializedBytes;extern "C" char ScriptExecuteRequestedCountAndReturnResult_UnknownRoleProcedureReferenceRecords[];extern "C" void _ZN6Script10InitializeEv(void*);extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void*,void*);extern "C" void _ZN6Script4LoadEPKvj(void*,const void*,unsigned);extern "C" void _ZN6Script7ExecuteEv(void*);
// Original: arm9/main @ 0x02095870; symbol: func_02095870; size: 0x8C.
extern "C" bool Script_ExecuteRequestedCountAndReturnResult(int unused,const void* script,unsigned size,int n,unsigned char* result){*(volatile unsigned short*)(ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage+6)=0;ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage[1]=0;ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage[2]=0;QuestExecuteOrderPayloadScript_UnknownRoleInitializedBytes=n;if(n<=0)return true;unsigned buffer[268];_ZN6Script10InitializeEv(buffer);_ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(buffer,ScriptExecuteRequestedCountAndReturnResult_UnknownRoleProcedureReferenceRecords);_ZN6Script4LoadEPKvj(buffer,script,size);_ZN6Script7ExecuteEv(buffer);*result=ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage[2];return false;}
