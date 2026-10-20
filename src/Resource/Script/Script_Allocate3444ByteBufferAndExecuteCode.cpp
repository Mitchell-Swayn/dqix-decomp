#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <Resource/Script.h>
extern "C" {
// Original data: arm9/main @ 0x2109ba4; symbol: data_02109ba4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned int *LoadAndExecuteScriptWithGlobalObject_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x20f15e8; symbol: data_020f15e8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000f4a0090265000000fca009026600000004a109020000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern Script::OpcodeLookupEntry ScriptAllocate3444ByteBufferAndExecuteCode_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x0209A470; symbol: func_0209a470; size: 0x80.
    void Script_Allocate3444ByteBufferAndExecuteCode(unsigned int *p,SafeAllocator *alloc,void *code,unsigned int len){
        Script script;
        void *data=alloc->Allocate(0xd74);
        p[0]=(unsigned int)data;
        if(data){
            LoadAndExecuteScriptWithGlobalObject_UnknownRoleZeroInitializedStorage=p;
            script.Initialize();
            script.SetOpcodeLookup(ScriptAllocate3444ByteBufferAndExecuteCode_UnknownRoleProcedureReferenceRecords);
            script.Load(code,len);
            script.Execute();
            LoadAndExecuteScriptWithGlobalObject_UnknownRoleZeroInitializedStorage=0;
        }
    }
}
