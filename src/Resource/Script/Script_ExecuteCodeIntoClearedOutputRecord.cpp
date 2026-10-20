#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x20f0ff8; symbol: data_020f0ff8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 660000006420080267000000102408020000000000000000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108ee8; symbol: data_02108ee8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void* memset(void*,int,unsigned);extern "C" unsigned CharacterGrowthRecordScriptBreakpoint_UnknownRoleZeroInitializedStorage[5];extern "C" Script::OpcodeLookupEntry ScriptExecuteCodeIntoClearedOutputRecord_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x0208274C; symbol: func_0208274c; size: 0x78.
extern "C" int Script_ExecuteCodeIntoClearedOutputRecord(void* output,const void* code,unsigned size,unsigned mode){memset(output,0,84);CharacterGrowthRecordScriptBreakpoint_UnknownRoleZeroInitializedStorage[4]=0;CharacterGrowthRecordScriptBreakpoint_UnknownRoleZeroInitializedStorage[1]=0;CharacterGrowthRecordScriptBreakpoint_UnknownRoleZeroInitializedStorage[2]=mode;CharacterGrowthRecordScriptBreakpoint_UnknownRoleZeroInitializedStorage[3]=(unsigned)output;CharacterGrowthRecordScriptBreakpoint_UnknownRoleZeroInitializedStorage[0]=0;Script s;s.Initialize();s.SetOpcodeLookup(ScriptExecuteCodeIntoClearedOutputRecord_UnknownRoleProcedureReferenceRecords);s.Load(code,size);s.Execute();return 0;}
