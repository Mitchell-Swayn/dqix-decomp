#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" {
// Original data: arm9/main @ 0x21098e0; symbol: data_021098e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int ScriptExecuteWithArgumentPointerAndContext_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x20f14dc; symbol: data_020f14dc.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000fc7809020000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Script::OpcodeLookupEntry ScriptExecuteWithArgumentPointerAndContext_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x02097AC0; symbol: func_02097ac0; size: 0x74.
void Script_ExecuteWithArgumentPointerAndContext(unsigned int context, unsigned int arg, void *code, unsigned int length) {
    if (code && length) {
        ScriptExecuteWithArgumentPointerAndContext_UnknownRoleZeroInitializedStorage[1] = context;
        ScriptExecuteWithArgumentPointerAndContext_UnknownRoleZeroInitializedStorage[0] = (unsigned int)&arg;
        Script script;
        script.Initialize(); script.SetOpcodeLookup(ScriptExecuteWithArgumentPointerAndContext_UnknownRoleProcedureReferenceRecords); script.Load(code,length); script.Execute();
    }
}
}
