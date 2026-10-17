#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
#include <std_library_functions.h>
extern "C" {
    extern char data_020f22e0[];
    extern char data_020f22f4[];
    void Script_ClearOwnerRecordAndExecuteCode(void *,void *,unsigned int);
// Original: arm9/main @ 0x020D3C28; symbol: func_020d3c28; size: 0x5C.
    void ClearStateAndLoadGP2ResourceUnderLoaderLock(unsigned char *p){
        unsigned int len;
        memset(p,0,180);
        *(int *)(p+180)=0;
        BackgroundLoader::AddLockGlobal();
        void *code=ExtractFileFromGP2(data_020f22e0,data_020f22f4,&len);
        if(code)Script_ClearOwnerRecordAndExecuteCode(p,code,len);
        BackgroundLoader::RemoveLockGlobal();
    }
}
