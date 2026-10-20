#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x20f0c78; symbol: data_020f0c78.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000101807026500000018180702660000002018070267000000741807020000000000000000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108d98; symbol: data_02108d98.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct State{unsigned short x,pad;unsigned a,b,c;};extern "C" State ScriptInvokeCachedOrParameterizedRecordId_UnknownRoleZeroInitializedStorage;extern "C" Script::OpcodeLookupEntry ScriptExecuteWithPairContextAndResetResult_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x02071C00; symbol: func_02071c00; size: 0x64.
extern "C" void Script_ExecuteWithPairContextAndResetResult(unsigned a,unsigned b,const void* code,unsigned size){ScriptInvokeCachedOrParameterizedRecordId_UnknownRoleZeroInitializedStorage.c=a;ScriptInvokeCachedOrParameterizedRecordId_UnknownRoleZeroInitializedStorage.b=b;ScriptInvokeCachedOrParameterizedRecordId_UnknownRoleZeroInitializedStorage.a=0;ScriptInvokeCachedOrParameterizedRecordId_UnknownRoleZeroInitializedStorage.x=0;Script s;s.Initialize();s.SetOpcodeLookup(ScriptExecuteWithPairContextAndResetResult_UnknownRoleProcedureReferenceRecords);s.Load(code,size);s.Execute();}
