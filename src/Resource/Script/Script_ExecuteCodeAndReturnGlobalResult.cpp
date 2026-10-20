#include <globaldefs.h>
ARM
#include <Resource/Script.h>
// Original data: arm9/main @ 0x20f13d8; symbol: data_020f13d8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f13dc; symbol: data_020f13dc.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 65000000804d090264000000784d090267000000e85409020000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109404; symbol: data_02109404.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct State{unsigned char pad;unsigned char running;unsigned char flag;unsigned char pad3[3];unsigned short result;};extern "C" {extern State ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage;extern short QuestExecuteOrderPayloadScript_UnknownRoleInitializedBytes;extern Script::OpcodeLookupEntry ScriptExecuteCodeAndReturnGlobalResult_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x020957F4; symbol: func_020957f4; size: 0x7C.
unsigned short Script_ExecuteCodeAndReturnGlobalResult(int unused,void* data,unsigned int size){ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage.result=0;ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage.running=1;ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage.flag=0;QuestExecuteOrderPayloadScript_UnknownRoleInitializedBytes=-1;Script script;script.Initialize();script.SetOpcodeLookup(ScriptExecuteCodeAndReturnGlobalResult_UnknownRoleProcedureReferenceRecords);script.Load(data,size);script.Execute();return ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage.result;}}
