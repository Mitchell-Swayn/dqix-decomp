#include <globaldefs.h>
ARM
#include <Resource/Script.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
// Original data: arm9/main @ 0x20f15c4; symbol: data_020f15c4.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000f49e09020000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char WeaponPosition_LoadConfigurationScript_PathDataBinWpnposBin[];extern "C" Script::OpcodeLookupEntry WeaponPositionLoadConfigurationScript_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x02099F6C; symbol: func_02099f6c; size: 0x7C.
extern "C" void WeaponPosition_LoadConfigurationScript(void* p){unsigned length;Script script;memset(p,0,0x150);BackgroundLoader::AddLockGlobal();void* data=LoadFileIntoMemory(WeaponPosition_LoadConfigurationScript_PathDataBinWpnposBin,Main_UnknownRoleZeroInitializedStorage_Variant6,&length);if(data){script.Initialize();script.SetOpcodeLookup(WeaponPositionLoadConfigurationScript_UnknownRoleProcedureReferenceRecords);script.Load(data,length);script.Execute();}BackgroundLoader::RemoveLockGlobal();}
