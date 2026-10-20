#include <globaldefs.h>
#include <std_library_functions.h>
#include <Resource/Script.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
extern "C" {
// Original data: arm9/main @ 0x20f15e8; symbol: data_020f15e8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000f4a0090265000000fca009026600000004a109020000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109ba4; symbol: data_02109ba4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char LoadAndExecuteScriptWithGlobalObject_PathDataPrmSkilltableBin[];extern unsigned int *LoadAndExecuteScriptWithGlobalObject_UnknownRoleZeroInitializedStorage;extern Script::OpcodeLookupEntry ScriptAllocate3444ByteBufferAndExecuteCode_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x0209A348; symbol: func_0209a348; size: 0x94.
void BackgroundLoader_LoadAndExecuteTemporaryOwnerScript(unsigned int *p,unsigned int arg){unsigned int len;Script script;BackgroundLoader::AddLockGlobal();void *code=LoadFileIntoMemory(LoadAndExecuteScriptWithGlobalObject_PathDataPrmSkilltableBin,Main_UnknownRoleZeroInitializedStorage_Variant6,&len);if(code){*p=arg;LoadAndExecuteScriptWithGlobalObject_UnknownRoleZeroInitializedStorage=p;script.Initialize();script.SetOpcodeLookup(ScriptAllocate3444ByteBufferAndExecuteCode_UnknownRoleProcedureReferenceRecords);script.Load(code,len);script.Execute();LoadAndExecuteScriptWithGlobalObject_UnknownRoleZeroInitializedStorage=0;}BackgroundLoader::RemoveLockGlobal();}
}
