#include <globaldefs.h>
#include <std_library_functions.h>
#include <Resource/Script.h>
extern "C" {
// Original data: arm9/main @ 0x20f1248; symbol: data_020f1248.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 66000000f4da08020000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108fc8; symbol: data_02108fc8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int WorldScriptRecordStageFirstMatchingPlacement_UnknownRoleZeroInitializedStorage[];unsigned int *Zone3D_GetMainInstance();extern Script::OpcodeLookupEntry ScriptExecuteWithCurrentZoneAndReturnGlobalResult_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x0208DC00; symbol: func_0208dc00; size: 0x74.
unsigned int Script_ExecuteWithCurrentZoneAndReturnGlobalResult(void *code,unsigned int len,unsigned int arg){WorldScriptRecordStageFirstMatchingPlacement_UnknownRoleZeroInitializedStorage[2]=arg;WorldScriptRecordStageFirstMatchingPlacement_UnknownRoleZeroInitializedStorage[0]=0;WorldScriptRecordStageFirstMatchingPlacement_UnknownRoleZeroInitializedStorage[1]=Zone3D_GetMainInstance()[2];Script script;script.Initialize();script.SetOpcodeLookup(ScriptExecuteWithCurrentZoneAndReturnGlobalResult_UnknownRoleProcedureReferenceRecords);script.Load(code,len);script.Execute();return WorldScriptRecordStageFirstMatchingPlacement_UnknownRoleZeroInitializedStorage[0];}
}
