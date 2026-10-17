#include <globaldefs.h>
ARM
#include <Memory/SafeAllocator.h>
#include <System/Memory.h>
#include <System/LoadToVRAM.h>
#include <System/Cache.h>
extern "C" unsigned GetGlobalStatePointer();extern "C" int TestWordMaskNonzero(unsigned,int);extern "C" void BuildSevenEntriesAndRenderFormattedValues(void*,void*,unsigned,unsigned),Text_RenderThreeNamesUsingGeneratedGlyphDescriptors(void*,void*,unsigned,unsigned),Text_RenderPanelUsingGeneratedGlyphDescriptors(void*,void*,unsigned,unsigned),Text_DrawTwoCenteredLinesWithFourGlyphs(void*,void*,unsigned,unsigned),System_WaitForInterruptOneAfterShortDelay();
// Original: arm9/main @ 0x020E0A78; symbol: func_020e0a78; size: 0xD4.
extern "C" int AllocateAndCopyPresentResourceBuffer(unsigned char* object){if(!*(SafeAllocator**)(object+0x76c))return 0;if(TestWordMaskNonzero(GetGlobalStatePointer(),0x41))return 0;void* buffer=(*(SafeAllocator**)(object+0x76c))->Allocate(*(unsigned*)(object+0x774));MI_CpuCopy8(*(void**)(object+0x770),buffer,*(unsigned*)(object+0x774));BuildSevenEntriesAndRenderFormattedValues(object,buffer,0,0x700);Text_RenderThreeNamesUsingGeneratedGlyphDescriptors(object,buffer,0x700,0xfc0);Text_RenderPanelUsingGeneratedGlyphDescriptors(object,buffer,0x16c0,0x9c0);Text_DrawTwoCenteredLinesWithFourGlyphs(object,buffer,0x2080,0xd00);System_WaitForInterruptOneAfterShortDelay();CleanInvalidateCacheRange(buffer,*(unsigned*)(object+0x774));LoadToSubObjVRAM(buffer,0,*(unsigned*)(object+0x774));(*(SafeAllocator**)(object+0x76c))->Free(buffer);return 1;}
