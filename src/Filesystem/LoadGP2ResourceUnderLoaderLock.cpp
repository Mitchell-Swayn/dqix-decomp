#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
extern "C" const char data_020f0a64[],data_020f0a7a[];
extern "C" void func_0206f01c(unsigned,unsigned,void*,unsigned);
// Original: arm9/main @ 0x0206EFD8; symbol: func_0206efd8; size: 0x44.
extern "C" void LoadGP2ResourceUnderLoaderLock(unsigned a,unsigned b) { unsigned size;BackgroundLoader::AddLockGlobal();void* file=ExtractFileFromGP2(data_020f0a64,data_020f0a7a,&size);func_0206f01c(a,b,file,size);BackgroundLoader::RemoveLockGlobal(); }
