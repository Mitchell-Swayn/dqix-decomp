#include <globaldefs.h>
#include <Resource/Script.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
// Original data: arm9/main @ 0x20f1524; symbol: data_020f1524.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 65000000b895090264000000b095090266000000c095090267000000f8950902690000009098090268000000889809020000000000000000.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109924; symbol: data_02109924.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Script_LoadFileAndExecuteWithTemporaryGlobalValue_PathDataMapMaplist9Bin[];extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant6[];extern "C" unsigned ScriptAllocateZoneTableEntries_UnknownRoleZeroInitializedStorage;extern "C" Script::OpcodeLookupEntry ScriptLoadFileAndExecuteWithTemporaryGlobalValue_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x020998C4; symbol: func_020998c4; size: 0x8C.
extern "C" ARM void Script_LoadFileAndExecuteWithTemporaryGlobalValue(unsigned value){unsigned size;BackgroundLoader::AddLockGlobal();void* p=LoadFileIntoMemory(Script_LoadFileAndExecuteWithTemporaryGlobalValue_PathDataMapMaplist9Bin,Main_UnknownRoleZeroInitializedStorage_Variant6,&size);if(p){ScriptAllocateZoneTableEntries_UnknownRoleZeroInitializedStorage=value;Script script;script.Initialize();script.SetOpcodeLookup(ScriptLoadFileAndExecuteWithTemporaryGlobalValue_UnknownRoleProcedureReferenceRecords);script.Load(p,size);script.Execute();ScriptAllocateZoneTableEntries_UnknownRoleZeroInitializedStorage=0;}BackgroundLoader::RemoveLockGlobal();}
