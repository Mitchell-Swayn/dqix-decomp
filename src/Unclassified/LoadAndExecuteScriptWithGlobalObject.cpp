#include <globaldefs.h>
#include "Resource/Script.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
extern "C" char data_020f1628[];extern "C" Script::OpcodeLookupEntry data_020f1608[];extern "C" unsigned* data_02109ba4;
// Original: arm9/main @ 0x0209A3DC; symbol: func_0209a3dc; size: 0x94.
extern "C" ARM void LoadAndExecuteScriptWithGlobalObject(unsigned* object,unsigned value){unsigned length;Script script;BackgroundLoader::AddLockGlobal();void* data=LoadFileIntoMemory(data_020f1628,data_0211e33c,&length);if(data){*object=value;data_02109ba4=object;script.Initialize();script.SetOpcodeLookup(data_020f1608);script.Load(data,length);script.Execute();data_02109ba4=0;}BackgroundLoader::RemoveLockGlobal();}
