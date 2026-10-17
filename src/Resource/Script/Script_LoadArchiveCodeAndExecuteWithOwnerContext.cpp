#include <globaldefs.h>
#include <Resource/Script.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
extern "C" {
    extern unsigned char data_02109d94[];
    extern char data_020f1917[];
    extern char data_020f192c[];
    extern Script::OpcodeLookupEntry data_020f18ec[];
// Original: arm9/main @ 0x020A13E4; symbol: func_020a13e4; size: 0x98.
    void Script_LoadArchiveCodeAndExecuteWithOwnerContext(void *p,void *context,int value,short index,unsigned char flag){
        unsigned int len;
        Script script;
        if(!context)return;
        *(void **)(data_02109d94+4)=p;
        *(void **)(data_02109d94+8)=context;
        *(int *)(data_02109d94+12)=value;
        *(short *)(data_02109d94+2)=index;
        data_02109d94[0]=flag;
        BackgroundLoader::AddLockGlobal();
        len=0;
        void *code=ExtractFileFromGP2(data_020f1917,data_020f192c,&len);
        if(code){
            script.Initialize();
            script.SetOpcodeLookup(data_020f18ec);
            script.Load(code,len);
            script.Execute();
        }BackgroundLoader::RemoveLockGlobal();
    }
}
