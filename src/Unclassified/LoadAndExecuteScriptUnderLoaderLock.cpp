#include <globaldefs.h>
#include <Resource/Script.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
extern "C" {
    extern char data_020f1b14[];
    extern unsigned char data_0211e33c[];
    extern Script::OpcodeLookupEntry data_020f1b04[];
// Original: arm9/main @ 0x020A6194; symbol: func_020a6194; size: 0x78.
    void LoadAndExecuteScriptUnderLoaderLock(){
        unsigned int len;
        Script script;
        BackgroundLoader::AddLockGlobal();
        len=0;
        void *code=LoadFileIntoMemory(data_020f1b14,data_0211e33c,&len);
        if(code){
            script.Initialize();
            script.SetOpcodeLookup(data_020f1b04);
            script.Load(code,len);
            script.Execute();
        }BackgroundLoader::RemoveLockGlobal();
    }
}
