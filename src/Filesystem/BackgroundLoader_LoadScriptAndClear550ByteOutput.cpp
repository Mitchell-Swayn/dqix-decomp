#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
#include <Resource/Script.h>
#include <std_library_functions.h>
extern "C" const char data_020f1668[];
extern "C" void** data_02109ba8;
extern "C" Script::OpcodeLookupEntry data_020f1640[];
// Original: arm9/main @ 0x0209A810; symbol: func_0209a810; size: 0xA4.
extern "C" void BackgroundLoader_LoadScriptAndClear550ByteOutput(void** owner,void* buffer) {unsigned size;Script script;BackgroundLoader::AddLockGlobal();if(LoadFileIntoMemory(data_020f1668,data_0211e33c,&size)){*owner=buffer;memset(buffer,0,0x550);data_02109ba8=owner;script.Initialize();script.SetOpcodeLookup(data_020f1640);script.Load(data_0211e33c,size);script.Execute();data_02109ba8=0;}BackgroundLoader::RemoveLockGlobal();}
