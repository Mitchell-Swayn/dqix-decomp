#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#include <System/Cache.h>
#include <System/LoadToVRAM.h>
extern "C" {unsigned char* TextContext_GetSharedInstance();void TextLayout_RenderFormattedScrollingText(void*,void*,int);void System_WaitForInterruptOneAfterShortDelay();
// Original: arm9/main @ 0x020233B8; symbol: func_020233b8; size: 0x84.
int Graphics_ReplicateSpriteDataAndUploadSubObjectVRAM(unsigned char* p,int sync){unsigned char* object=TextContext_GetSharedInstance();int offset=0;int i=0;unsigned char* dst=*(unsigned char**)(object+0x60);for(;i<19;i++){memcpy(dst+offset,p+0xbf0,64);offset+=64;}TextLayout_RenderFormattedScrollingText(p,dst,0);if(sync)System_WaitForInterruptOneAfterShortDelay();CleanInvalidateCacheRange(dst,0x4c0);LoadToSubObjVRAM(dst,0x2c00,0x4c0);return 1;}}
