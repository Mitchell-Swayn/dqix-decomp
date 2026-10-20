#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" {
// Original data: arm9/main @ 0x2108ed8; symbol: data_02108ed8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern void *ScriptAppendIndexedHalfwordRecord_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x20f0f88; symbol: data_020f0f88.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 640000001ced07026500000048ed07026600000090ee070267000000f8ee07020000000000000000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern Script::OpcodeLookupEntry ScriptExecuteCodeWithOptionalContext_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x0207EF74; symbol: func_0207ef74; size: 0x68.
    void Script_ExecuteCodeWithOptionalContext(void *p,void *context,void *code,unsigned int len){
        Script script;
        if(context&&code&&len){
            ScriptAppendIndexedHalfwordRecord_UnknownRoleZeroInitializedStorage[1]=p;
            ScriptAppendIndexedHalfwordRecord_UnknownRoleZeroInitializedStorage[0]=context;
            script.Initialize();
            script.SetOpcodeLookup(ScriptExecuteCodeWithOptionalContext_UnknownRoleProcedureReferenceRecords);
            script.Load(code,len);
            script.Execute();
        }
    }
}
