#include "globaldefs.h"
#pragma optimize_for_size on
ARM
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int ResourceFile_FormatNatPath(char*,const char*,...);extern "C" void _Z18LoadFileIntoMemoryPKcPvPj(const char*,void*,unsigned*);extern "C" void* Filesystem_ExtractLocalizedGp2FileToScratch(void*,const char*,unsigned*);extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant6[];
// Original: arm9/main @ 0x020E0574; symbol: func_020e0574; size: 0x84.
extern "C" void* ResourceFile_LoadFormattedPathFromDiskOrGP2(const char*path,unsigned*size,unsigned mode,void*archive){char buffer[64];void*result;if(!path)return 0;*size=0;ResourceFile_FormatNatPath(buffer,path,mode,0);if(!archive){_Z18LoadFileIntoMemoryPKcPvPj(buffer,Main_UnknownRoleZeroInitializedStorage_Variant6,size);if(!*size)goto fail;result=Main_UnknownRoleZeroInitializedStorage_Variant6;goto done;}result=Filesystem_ExtractLocalizedGp2FileToScratch(archive,buffer,size);if(result)goto done;fail:result=0;done:return result;}
