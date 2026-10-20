#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
extern "C" const char LoadGP2ResourceUnderLoaderLock_PathDataPrmMonDataGp2[],LoadGP2ResourceUnderLoaderLock_MarkupMonDataLGNat[];
extern "C" void MonsterData_LoadOwnedCopyAndRelocateStrings(unsigned,unsigned,void*,unsigned);
// Original: arm9/main @ 0x0206EFD8; symbol: func_0206efd8; size: 0x44.
extern "C" void LoadGP2ResourceUnderLoaderLock(unsigned a,unsigned b) { unsigned size;BackgroundLoader::AddLockGlobal();void* file=Filesystem_ExtractLocalizedGp2FileToScratch(LoadGP2ResourceUnderLoaderLock_PathDataPrmMonDataGp2,LoadGP2ResourceUnderLoaderLock_MarkupMonDataLGNat,&size);MonsterData_LoadOwnedCopyAndRelocateStrings(a,b,file,size);BackgroundLoader::RemoveLockGlobal(); }
