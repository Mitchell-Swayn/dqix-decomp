#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
extern "C" char data_020f0b64[];extern "C" unsigned char data_0211e33c[];extern "C" void func_02070a30(unsigned,unsigned,void*,unsigned);
// Original: arm9/main @ 0x020709EC; symbol: func_020709ec; size: 0x44.
extern "C" ARM void BackgroundLoader_LoadFileAndPassToResourceInitializer(unsigned a,unsigned b){unsigned size;BackgroundLoader::AddLockGlobal();void* p=LoadFileIntoMemory(data_020f0b64,data_0211e33c,&size);func_02070a30(a,b,p,size);BackgroundLoader::RemoveLockGlobal();}
