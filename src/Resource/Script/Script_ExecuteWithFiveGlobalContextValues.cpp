#pragma thumb off
#pragma optimization_level 4

#include <Resource/Script.h>
struct Context{unsigned char kind,pad;unsigned short id;int first,second,third;};
// Original data: arm9/main @ 0x20f18ec; symbol: data_020f18ec.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000bc100a0265000000c4100a0266000000cc100a026700000080110a020000000000000000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109d94; symbol: data_02109d94.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {extern Context ScriptSumSelectedFourHalfwordParameters_UnknownRoleZeroInitializedStorage;extern Script::OpcodeLookupEntry ScriptExecuteWithFiveGlobalContextValues_UnknownRoleProcedureReferenceRecords[];}
// Original: arm9/main @ 0x020A147C; symbol: func_020a147c; size: 0x80.
extern "C" void Script_ExecuteWithFiveGlobalContextValues(int first,int second,const void* code,unsigned length,int third,unsigned short id,unsigned char kind){if(second && code && length){ScriptSumSelectedFourHalfwordParameters_UnknownRoleZeroInitializedStorage.first=first;ScriptSumSelectedFourHalfwordParameters_UnknownRoleZeroInitializedStorage.second=second;ScriptSumSelectedFourHalfwordParameters_UnknownRoleZeroInitializedStorage.third=third;ScriptSumSelectedFourHalfwordParameters_UnknownRoleZeroInitializedStorage.id=id;ScriptSumSelectedFourHalfwordParameters_UnknownRoleZeroInitializedStorage.kind=kind;Script script;script.Initialize();script.SetOpcodeLookup(ScriptExecuteWithFiveGlobalContextValues_UnknownRoleProcedureReferenceRecords);script.Load(code,length);script.Execute();}}
