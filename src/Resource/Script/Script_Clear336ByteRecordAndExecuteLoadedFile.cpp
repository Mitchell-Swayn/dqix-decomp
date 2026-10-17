#include <globaldefs.h>
ARM
#include <Resource/Script.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
extern "C" char data_020f15d4[];extern "C" Script::OpcodeLookupEntry data_020f15c4[];
// Original: arm9/main @ 0x02099F6C; symbol: func_02099f6c; size: 0x7C.
extern "C" void Script_Clear336ByteRecordAndExecuteLoadedFile(void* p){unsigned length;Script script;memset(p,0,0x150);BackgroundLoader::AddLockGlobal();void* data=LoadFileIntoMemory(data_020f15d4,data_0211e33c,&length);if(data){script.Initialize();script.SetOpcodeLookup(data_020f15c4);script.Load(data,length);script.Execute();}BackgroundLoader::RemoveLockGlobal();}
