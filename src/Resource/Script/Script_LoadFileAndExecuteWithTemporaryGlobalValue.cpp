#include <globaldefs.h>
#include <Resource/Script.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
extern "C" char data_020f155c[];extern "C" unsigned char data_0211e33c[];extern "C" unsigned data_02109924;extern "C" Script::OpcodeLookupEntry data_020f1524[];
// Original: arm9/main @ 0x020998C4; symbol: func_020998c4; size: 0x8C.
extern "C" ARM void Script_LoadFileAndExecuteWithTemporaryGlobalValue(unsigned value){unsigned size;BackgroundLoader::AddLockGlobal();void* p=LoadFileIntoMemory(data_020f155c,data_0211e33c,&size);if(p){data_02109924=value;Script script;script.Initialize();script.SetOpcodeLookup(data_020f1524);script.Load(p,size);script.Execute();data_02109924=0;}BackgroundLoader::RemoveLockGlobal();}
