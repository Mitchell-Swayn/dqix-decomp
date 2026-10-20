#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#include <Filesystem/BackgroundLoader.h>
extern "C" void* ResourceFile_LoadFormattedPathFromDiskOrGP2(void*,unsigned*,unsigned,unsigned);extern "C" int ResourceStringTable_CopyTextByKey(void*,void*,unsigned,int);
// Original: arm9/main @ 0x020E04F4; symbol: func_020e04f4; size: 0x80.
extern "C" int LoadAndProcessDataWithOptionalBackgroundLoaderLock(void* owner,void* input,int count,unsigned flags,unsigned char locked,unsigned arg) {if(!owner || !input || count<0)return 0;if(locked)BackgroundLoader::AddLockGlobal();unsigned length;void* data=ResourceFile_LoadFormattedPathFromDiskOrGP2(input,&length,flags,arg);int result=ResourceStringTable_CopyTextByKey(owner,data,length,count);if(locked)BackgroundLoader::RemoveLockGlobal();return result; }
