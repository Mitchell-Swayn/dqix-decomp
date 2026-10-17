#include "globaldefs.h"
#pragma optimize_for_size on
ARM
extern "C" int FormatTextAndReplaceMatchingSuffix(char*,const char*,...);extern "C" void _Z18LoadFileIntoMemoryPKcPvPj(const char*,void*,unsigned*);extern "C" void* ExtractFileFromGP2(void*,const char*,unsigned*);extern "C" unsigned char data_0211e33c[];
// Original: arm9/main @ 0x020E0574; symbol: func_020e0574; size: 0x84.
extern "C" void* ResourceFile_LoadFormattedPathFromDiskOrGP2(const char*path,unsigned*size,unsigned mode,void*archive){char buffer[64];void*result;if(!path)return 0;*size=0;FormatTextAndReplaceMatchingSuffix(buffer,path,mode,0);if(!archive){_Z18LoadFileIntoMemoryPKcPvPj(buffer,data_0211e33c,size);if(!*size)goto fail;result=data_0211e33c;goto done;}result=ExtractFileFromGP2(archive,buffer,size);if(result)goto done;fail:result=0;done:return result;}
