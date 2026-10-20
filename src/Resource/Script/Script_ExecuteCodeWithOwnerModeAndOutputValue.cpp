#include <globaldefs.h>
ARM
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
struct State {unsigned char enabled,pad;unsigned short mode;unsigned arg;unsigned* value;unsigned result,owner;};extern "C" State ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage;extern "C" Script::OpcodeLookupEntry ScriptExecuteCodeWithGlobalContextValues_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x02072928; symbol: func_02072928; size: 0x8C.
extern "C" void Script_ExecuteCodeWithOwnerModeAndOutputValue(unsigned owner,void* code,unsigned size,unsigned value,unsigned arg,unsigned char enabled) {Script script;ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.owner=owner;ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.result=0;ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.value=&value;ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.mode=1;ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.arg=arg;ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.enabled=enabled;script.Initialize();script.SetOpcodeLookup(ScriptExecuteCodeWithGlobalContextValues_UnknownRoleProcedureReferenceRecords);script.Load(code,size);script.Execute(); }
