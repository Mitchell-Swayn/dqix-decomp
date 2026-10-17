#include <globaldefs.h>
#include <std_library_functions.h>
#include <Memory/SafeAllocator.h>
#include <Resource/Script.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
extern "C" {
extern char data_020f14b0[];extern unsigned int data_02109404[];extern Script::OpcodeLookupEntry data_020f1444[];
// Original: arm9/main @ 0x02096524; symbol: func_02096524; size: 0x88.
void BackgroundLoader_LoadAndExecuteRecordScript(char *p){unsigned int len;Script script;BackgroundLoader::AddLockGlobal();void *code=LoadFileIntoMemory(data_020f14b0,data_0211e33c,&len);if(code){data_02109404[4]=(unsigned int)(p+0xac);unsigned int size=len;script.Initialize();script.SetOpcodeLookup(data_020f1444);script.Load(code,size);script.Execute();}BackgroundLoader::RemoveLockGlobal();}
}
