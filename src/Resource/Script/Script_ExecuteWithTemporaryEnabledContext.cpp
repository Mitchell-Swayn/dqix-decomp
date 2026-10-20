#include <globaldefs.h>
#pragma optimize_for_size on
#include "Resource/Script.h"
struct ScriptContext {unsigned owner,a,b,c,enabled,count,reserved;};
// Original data: arm9/main @ 0x2109bb0; symbol: data_02109bb0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" ScriptContext* ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x20f16c0; symbol: data_020f16c0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 640000001cba09026500000024ba0902660000002cba09026700000070ba0902680000001cbb0902690000006cbb09020000000000000000.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Script::OpcodeLookupEntry ScriptExecuteWithTemporaryEnabledContext_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x0209BC98; symbol: func_0209bc98; size: 0xA0.
extern "C" ARM void Script_ExecuteWithTemporaryEnabledContext(unsigned owner,const void* code,unsigned size,unsigned unused,unsigned a,unsigned b,unsigned c)
{
    if (!code) return;
    ScriptContext context;
    ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage=&context;
    ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage->owner=owner;
    ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage->a=a;
    ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage->b=b;
    ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage->c=c;
    ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage->enabled=1;
    ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage->count=0;
    Script script;
    script.Initialize();script.SetOpcodeLookup(ScriptExecuteWithTemporaryEnabledContext_UnknownRoleProcedureReferenceRecords);
    script.Load(code,size);script.Execute();
}
