#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
#include <Resource/Script.h>
#include <std_library_functions.h>
extern "C" const char BackgroundLoader_LoadScriptAndClear550ByteOutput_PathDataPrmSpelltableBin[];
// Original data: arm9/main @ 0x2109ba8; symbol: data_02109ba8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void** ScriptAllocateZeroedStateAndExecute_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x20f1640; symbol: data_020f1640.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 640000006ca709026500000074a70902660000007ca7090267000000bca709020000000000000000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Script::OpcodeLookupEntry ScriptAllocateZeroedStateAndExecute_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x0209A810; symbol: func_0209a810; size: 0xA4.
extern "C" void BackgroundLoader_LoadScriptAndClear550ByteOutput(void** owner,void* buffer) {unsigned size;Script script;BackgroundLoader::AddLockGlobal();if(LoadFileIntoMemory(BackgroundLoader_LoadScriptAndClear550ByteOutput_PathDataPrmSpelltableBin,Main_UnknownRoleZeroInitializedStorage_Variant6,&size)){*owner=buffer;memset(buffer,0,0x550);ScriptAllocateZeroedStateAndExecute_UnknownRoleZeroInitializedStorage=owner;script.Initialize();script.SetOpcodeLookup(ScriptAllocateZeroedStateAndExecute_UnknownRoleProcedureReferenceRecords);script.Load(Main_UnknownRoleZeroInitializedStorage_Variant6,size);script.Execute();ScriptAllocateZeroedStateAndExecute_UnknownRoleZeroInitializedStorage=0;}BackgroundLoader::RemoveLockGlobal();}
