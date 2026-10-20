#include <globaldefs.h>
#include <Resource/Script.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
extern "C" {
    extern char LoadAndExecuteScriptUnderLoaderLock_PathDataBinPercolBin[];
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant6[];
// Original data: arm9/main @ 0x20f1b04; symbol: data_020f1b04.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 6500000090600a020000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern Script::OpcodeLookupEntry LoadAndExecuteScriptUnderLoaderLock_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x020A6194; symbol: func_020a6194; size: 0x78.
    void LoadAndExecuteScriptUnderLoaderLock(){
        unsigned int len;
        Script script;
        BackgroundLoader::AddLockGlobal();
        len=0;
        void *code=LoadFileIntoMemory(LoadAndExecuteScriptUnderLoaderLock_PathDataBinPercolBin,Main_UnknownRoleZeroInitializedStorage_Variant6,&len);
        if(code){
            script.Initialize();
            script.SetOpcodeLookup(LoadAndExecuteScriptUnderLoaderLock_UnknownRoleProcedureReferenceRecords);
            script.Load(code,len);
            script.Execute();
        }BackgroundLoader::RemoveLockGlobal();
    }
}
