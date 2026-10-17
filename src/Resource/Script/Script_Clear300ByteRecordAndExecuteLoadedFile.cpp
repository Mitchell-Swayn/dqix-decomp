#include <globaldefs.h>
#include <Resource/Script.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
#include <std_library_functions.h>
extern "C" {
    extern char data_020f15ac[];
    extern unsigned char data_0211e33c[];
    extern Script::OpcodeLookupEntry data_020f1574[];
// Original: arm9/main @ 0x02099CB8; symbol: func_02099cb8; size: 0x7C.
    void Script_Clear300ByteRecordAndExecuteLoadedFile(void *p){
        unsigned int len;
        Script script;
        memset(p,0,300);
        BackgroundLoader::AddLockGlobal();
        void *code=LoadFileIntoMemory(data_020f15ac,data_0211e33c,&len);
        if(code){
            script.Initialize();
            script.SetOpcodeLookup(data_020f1574);
            script.Load(code,len);
            script.Execute();
        }BackgroundLoader::RemoveLockGlobal();
    }
}
