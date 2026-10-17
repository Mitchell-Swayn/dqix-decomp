#include <globaldefs.h>
#include <Resource/Script.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
struct State{unsigned char flag,pad;unsigned short count;unsigned value;unsigned* params;unsigned index,owner;};extern "C" State data_02108db0;extern "C" Script::OpcodeLookupEntry data_020f0cc8[];
// Original: arm9/main @ 0x020727F8; symbol: func_020727f8; size: 0xB4.
extern "C" ARM void BackgroundLoader_LoadAndExecuteMessageScript(unsigned owner,const char* path,unsigned parameters,unsigned value,unsigned char flag){unsigned size;BackgroundLoader::AddLockGlobal();void* code=LoadFileIntoMemory(path,data_0211e33c,&size);if(code){data_02108db0.owner=owner;data_02108db0.index=0;data_02108db0.params=&parameters;data_02108db0.count=1;data_02108db0.value=value;data_02108db0.flag=flag;Script script;script.Initialize();script.SetOpcodeLookup(data_020f0cc8);script.Load(code,size);script.Execute();}BackgroundLoader::RemoveLockGlobal();}
