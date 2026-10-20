#include <globaldefs.h>
#include <Resource/Script.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
extern "C" {
// Original data: arm9/main @ 0x2109d94; symbol: data_02109d94.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char ScriptSumSelectedFourHalfwordParameters_UnknownRoleZeroInitializedStorage[];
    extern char Script_LoadArchiveCodeAndExecuteWithOwnerContext_PathDataBinTtldataGp2[];
    extern char Script_LoadArchiveCodeAndExecuteWithOwnerContext_MarkupTtldataLGBin[];
// Original data: arm9/main @ 0x20f18ec; symbol: data_020f18ec.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000bc100a0265000000c4100a0266000000cc100a026700000080110a020000000000000000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern Script::OpcodeLookupEntry ScriptExecuteWithFiveGlobalContextValues_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x020A13E4; symbol: func_020a13e4; size: 0x98.
    void Script_LoadArchiveCodeAndExecuteWithOwnerContext(void *p,void *context,int value,short index,unsigned char flag){
        unsigned int len;
        Script script;
        if(!context)return;
        *(void **)(ScriptSumSelectedFourHalfwordParameters_UnknownRoleZeroInitializedStorage+4)=p;
        *(void **)(ScriptSumSelectedFourHalfwordParameters_UnknownRoleZeroInitializedStorage+8)=context;
        *(int *)(ScriptSumSelectedFourHalfwordParameters_UnknownRoleZeroInitializedStorage+12)=value;
        *(short *)(ScriptSumSelectedFourHalfwordParameters_UnknownRoleZeroInitializedStorage+2)=index;
        ScriptSumSelectedFourHalfwordParameters_UnknownRoleZeroInitializedStorage[0]=flag;
        BackgroundLoader::AddLockGlobal();
        len=0;
        void *code=Filesystem_ExtractLocalizedGp2FileToScratch(Script_LoadArchiveCodeAndExecuteWithOwnerContext_PathDataBinTtldataGp2,Script_LoadArchiveCodeAndExecuteWithOwnerContext_MarkupTtldataLGBin,&len);
        if(code){
            script.Initialize();
            script.SetOpcodeLookup(ScriptExecuteWithFiveGlobalContextValues_UnknownRoleProcedureReferenceRecords);
            script.Load(code,len);
            script.Execute();
        }BackgroundLoader::RemoveLockGlobal();
    }
}
