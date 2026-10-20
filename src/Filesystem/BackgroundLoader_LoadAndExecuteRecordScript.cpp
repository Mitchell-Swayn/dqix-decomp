#include <globaldefs.h>
#include <std_library_functions.h>
#include <Memory/SafeAllocator.h>
#include <Resource/Script.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
extern "C" {
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
extern char BackgroundLoader_LoadAndExecuteRecordScript_PathDataScenarioQuestidtblBin[];extern unsigned int ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage[];extern Script::OpcodeLookupEntry QuestExecuteOrderPayloadScript_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x02096524; symbol: func_02096524; size: 0x88.
void BackgroundLoader_LoadAndExecuteRecordScript(char *p){unsigned int len;Script script;BackgroundLoader::AddLockGlobal();void *code=LoadFileIntoMemory(BackgroundLoader_LoadAndExecuteRecordScript_PathDataScenarioQuestidtblBin,Main_UnknownRoleZeroInitializedStorage_Variant6,&len);if(code){ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage[4]=(unsigned int)(p+0xac);unsigned int size=len;script.Initialize();script.SetOpcodeLookup(QuestExecuteOrderPayloadScript_UnknownRoleProcedureReferenceRecords);script.Load(code,size);script.Execute();}BackgroundLoader::RemoveLockGlobal();}
}
