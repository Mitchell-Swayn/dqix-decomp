#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
#include <std_library_functions.h>
extern "C" {
    extern char ClearStateAndLoadGP2ResourceUnderLoaderLock_PathDataBinAttnpcGp2[];
    extern char ClearStateAndLoadGP2ResourceUnderLoaderLock_MarkupAttnpcLGBin[];
    void NpcAttributes_LoadRecordsFromScript(void *,void *,unsigned int);
// Original: arm9/main @ 0x020D3C28; symbol: func_020d3c28; size: 0x5C.
    void ClearStateAndLoadGP2ResourceUnderLoaderLock(unsigned char *p){
        unsigned int len;
        memset(p,0,180);
        *(int *)(p+180)=0;
        BackgroundLoader::AddLockGlobal();
        void *code=Filesystem_ExtractLocalizedGp2FileToScratch(ClearStateAndLoadGP2ResourceUnderLoaderLock_PathDataBinAttnpcGp2,ClearStateAndLoadGP2ResourceUnderLoaderLock_MarkupAttnpcLGBin,&len);
        if(code)NpcAttributes_LoadRecordsFromScript(p,code,len);
        BackgroundLoader::RemoveLockGlobal();
    }
}
