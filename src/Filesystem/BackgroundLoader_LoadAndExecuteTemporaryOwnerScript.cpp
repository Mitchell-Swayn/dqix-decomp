#include <globaldefs.h>
#include <std_library_functions.h>
#include <Resource/Script.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
extern "C" {
extern char data_020f1628[];extern unsigned int *data_02109ba4;extern Script::OpcodeLookupEntry data_020f15e8[];
// Original: arm9/main @ 0x0209A348; symbol: func_0209a348; size: 0x94.
void BackgroundLoader_LoadAndExecuteTemporaryOwnerScript(unsigned int *p,unsigned int arg){unsigned int len;Script script;BackgroundLoader::AddLockGlobal();void *code=LoadFileIntoMemory(data_020f1628,data_0211e33c,&len);if(code){*p=arg;data_02109ba4=p;script.Initialize();script.SetOpcodeLookup(data_020f15e8);script.Load(code,len);script.Execute();data_02109ba4=0;}BackgroundLoader::RemoveLockGlobal();}
}
