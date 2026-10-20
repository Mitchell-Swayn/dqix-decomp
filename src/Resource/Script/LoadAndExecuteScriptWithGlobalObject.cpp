#include <globaldefs.h>
#include "Resource/Script.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
// Original data: arm9/main @ 0x20f1608; symbol: data_020f1608.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000f4a0090265000000fca009026600000018a209020000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109ba4; symbol: data_02109ba4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char LoadAndExecuteScriptWithGlobalObject_PathDataPrmSkilltableBin[];extern "C" Script::OpcodeLookupEntry LoadAndExecuteScriptWithGlobalObject_UnknownRoleProcedureReferenceRecords[];extern "C" unsigned* LoadAndExecuteScriptWithGlobalObject_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x0209A3DC; symbol: func_0209a3dc; size: 0x94.
extern "C" ARM void LoadAndExecuteScriptWithGlobalObject(unsigned* object,unsigned value){unsigned length;Script script;BackgroundLoader::AddLockGlobal();void* data=LoadFileIntoMemory(LoadAndExecuteScriptWithGlobalObject_PathDataPrmSkilltableBin,Main_UnknownRoleZeroInitializedStorage_Variant6,&length);if(data){*object=value;LoadAndExecuteScriptWithGlobalObject_UnknownRoleZeroInitializedStorage=object;script.Initialize();script.SetOpcodeLookup(LoadAndExecuteScriptWithGlobalObject_UnknownRoleProcedureReferenceRecords);script.Load(data,length);script.Execute();LoadAndExecuteScriptWithGlobalObject_UnknownRoleZeroInitializedStorage=0;}BackgroundLoader::RemoveLockGlobal();}
