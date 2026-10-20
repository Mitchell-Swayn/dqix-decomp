#include <globaldefs.h>
#include <Resource/Script.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
extern "C" {
    extern char LoadAndExecuteFixedScriptUnderLoaderLock_PathDataBinMapbgmBin[];
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant6[];
// Original data: arm9/main @ 0x20f1718; symbol: data_020f1718.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 0100000074cb09020200000094cb09020000000000000000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern Script::OpcodeLookupEntry LoadAndExecuteFixedScriptUnderLoaderLock_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x0209CBCC; symbol: func_0209cbcc; size: 0x70.
    void LoadAndExecuteFixedScriptUnderLoaderLock(){
        unsigned int len;
        Script script;
        BackgroundLoader::AddLockGlobal();
        if(LoadFileIntoMemory(LoadAndExecuteFixedScriptUnderLoaderLock_PathDataBinMapbgmBin,Main_UnknownRoleZeroInitializedStorage_Variant6,&len)){
            script.Initialize();
            script.SetOpcodeLookup(LoadAndExecuteFixedScriptUnderLoaderLock_UnknownRoleProcedureReferenceRecords);
            script.Load(Main_UnknownRoleZeroInitializedStorage_Variant6,len);
            script.Execute();
        }BackgroundLoader::RemoveLockGlobal();
    }
}
