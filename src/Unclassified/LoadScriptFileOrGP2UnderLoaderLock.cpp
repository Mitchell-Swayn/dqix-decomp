#include <globaldefs.h>
#include "Resource/Script.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
extern "C" char data_020f1088[],data_020f109e[];extern "C" Script::OpcodeLookupEntry data_020f1048[];extern "C" unsigned data_02108efc[];
// Original: arm9/main @ 0x02089DE8; symbol: func_02089de8; size: 0xB8.
extern "C" ARM void LoadScriptFileOrGP2UnderLoaderLock(unsigned object,unsigned allocator,const char* path){unsigned length;Script script;BackgroundLoader::AddLockGlobal();void* buffer=data_0211e33c;void* data;if(path)data=LoadFileIntoMemory(path,buffer,&length);else data=ExtractFileFromGP2(data_020f1088,data_020f109e,&length);if(data){data_02108efc[0]=object;data_02108efc[3]=allocator;data_02108efc[2]=0;data_02108efc[1]=0;script.Initialize();script.SetOpcodeLookup(data_020f1048);script.Load(data,length);script.Execute();}BackgroundLoader::RemoveLockGlobal();}
