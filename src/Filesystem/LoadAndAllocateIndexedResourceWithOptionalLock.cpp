#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
extern "C" void*Filesystem_LoadFormattedFileOrArchiveInnerFile(void*,unsigned*,unsigned,unsigned);extern "C" void*Record_CopyIndexedTwelveByteLookupResult(void*,void*,unsigned,int);
// Original: arm9/main @ 0x020E54BC; symbol: func_020e54bc; size: 0x80.
extern "C" ARM void* LoadAndAllocateIndexedResourceWithOptionalLock(void*allocator,void*source,int index,unsigned length,unsigned char lock,unsigned flags){if(!allocator||!source||index<0)return 0;unsigned actual;if(lock)BackgroundLoader::AddLockGlobal();void*data=Filesystem_LoadFormattedFileOrArchiveInnerFile(source,&actual,length,flags);void*result=Record_CopyIndexedTwelveByteLookupResult(allocator,data,actual,index);if(lock)BackgroundLoader::RemoveLockGlobal();return result;}
