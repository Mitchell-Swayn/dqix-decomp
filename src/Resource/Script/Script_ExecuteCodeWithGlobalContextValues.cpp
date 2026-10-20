#include <globaldefs.h>
#include <Resource/Script.h>
// Original data: arm9/main @ 0x20f0cc8; symbol: data_020f0cc8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 640000001826070265000000202607026600000028260702670000007c2607020000000000000000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108db0; symbol: data_02108db0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Context {unsigned char flag,pad;unsigned short value;unsigned zero;void* a;void* b;void* c;};extern "C" Context ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage;extern "C" Script::OpcodeLookupEntry ScriptExecuteCodeWithGlobalContextValues_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x020728AC; symbol: func_020728ac; size: 0x7C.
extern "C" void Script_ExecuteCodeWithGlobalContextValues(void* a,void* b,const void* code,unsigned length,void* c,unsigned short value,unsigned char flag) {ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.c=a;ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.b=b;ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.a=c;ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.value=value;ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.zero=0;ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.flag=flag;Script script;script.Initialize();script.SetOpcodeLookup(ScriptExecuteCodeWithGlobalContextValues_UnknownRoleProcedureReferenceRecords);script.Load(code,length);script.Execute();}
