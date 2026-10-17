#include <globaldefs.h>
#include <Resource/Script.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
extern "C" {
    extern char data_020f1744[];
    extern unsigned char data_0211e33c[];
    extern Script::OpcodeLookupEntry data_020f1718[];
// Original: arm9/main @ 0x0209CBCC; symbol: func_0209cbcc; size: 0x70.
    void LoadAndExecuteFixedScriptUnderLoaderLock(){
        unsigned int len;
        Script script;
        BackgroundLoader::AddLockGlobal();
        if(LoadFileIntoMemory(data_020f1744,data_0211e33c,&len)){
            script.Initialize();
            script.SetOpcodeLookup(data_020f1718);
            script.Load(data_0211e33c,len);
            script.Execute();
        }BackgroundLoader::RemoveLockGlobal();
    }
}
