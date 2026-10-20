#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" {
// Original data: arm9/main @ 0x2108740; symbol: data_02108740.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern void *ScriptWriteGlobalHalfword2A_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x20f051c; symbol: data_020f051c.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 6400000034e00502650000003ce00502660000005ce00502670000007ce005026800000084e0050269000000b0e005026a000000b8e005026b000000c0e00502 ...; full span in module reference.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern Script::OpcodeLookupEntry ScriptInitializeAndExecuteOwnerContextCode_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x0205E104; symbol: func_0205e104; size: 0x68.
    void Script_InitializeAndExecuteOwnerContextCode(void *p,void *context,void *code,unsigned int len){
        Script script;
        if(p&&code&&len){
            ScriptWriteGlobalHalfword2A_UnknownRoleZeroInitializedStorage[1]=p;
            ScriptWriteGlobalHalfword2A_UnknownRoleZeroInitializedStorage[0]=context;
            script.Initialize();
            script.SetOpcodeLookup(ScriptInitializeAndExecuteOwnerContextCode_UnknownRoleProcedureReferenceRecords);
            script.Load(code,len);
            script.Execute();
        }
    }
}
