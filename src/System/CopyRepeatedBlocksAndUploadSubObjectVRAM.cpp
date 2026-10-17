#include <globaldefs.h>
#include "System/Cache.h"
struct Resource {char pad[0x60];void* buffer;};extern "C" {Resource* ReadWordFieldAtOffset1C();void* memcpy(void*,const void*,unsigned);void Text_GenerateGlyphLayoutAndRenderAdjustedLabel(void*,void*,int);void System_WaitForInterruptOneAfterShortDelay();void LoadToSubObjVRAM(void*,unsigned,unsigned);
// Original: arm9/main @ 0x02023330; symbol: func_02023330; size: 0x88.
int CopyRepeatedBlocksAndUploadSubObjectVRAM(char* p,int wait){Resource* r=ReadWordFieldAtOffset1C();int offset=0;int i=0;char* dst=(char*)r->buffer;for(;i<18;++i){memcpy(dst+offset,p+0xbf0,0x40);offset+=0x40;}Text_GenerateGlyphLayoutAndRenderAdjustedLabel(p,dst,0);if(wait)System_WaitForInterruptOneAfterShortDelay();CleanInvalidateCacheRange(dst,0x480);LoadToSubObjVRAM(dst,0x2c20,0x480);return 1;} }
