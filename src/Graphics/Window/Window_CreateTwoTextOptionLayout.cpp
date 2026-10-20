#include <globaldefs.h>
#include <Graphics/VRAMStaging.h>
ARM
#pragma opt_common_subs off
struct WindowLayout { unsigned char pad[0x38]; unsigned char x,y,width,height; };
struct Window { void* staging; WindowLayout* layout; signed char count; };
extern "C" const char* Text_LookupStandardString(int);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*, unsigned char);
extern "C" int Graphics_PartitionObjectAndComputeVRAMBudget(Window*, int);
extern "C" void* Window_AllocateStagingBufferAndInitializeTextEntries(Window*);
extern "C" void Window_DrawTiledFrameBorder(Window*);
extern "C" void Text_RenderEntryAndStoreMeasuredRectangle(Window*, int, int, int, const char*, unsigned char, unsigned char);
extern "C" void Graphics_StagePresentResourceRegion(Window*);
// Original: arm9/main @ 0x020E1CDC; symbol: func_020e1cdc; size: 0x148.
extern "C" int Window_CreateTwoTextOptionLayout(Window* window, int allocation) {
 int result;
 if (!window->layout) result=1;
 else {
 window->layout->x=0xc2;
 window->layout->y=0x48;
 window->layout->width=0x3c;
 window->layout->height=0x2c;
 const char* first=Text_LookupStandardString(0x1b);
 const char* second=Text_LookupStandardString(0x1c);
 int width=TextLayout_ComputeWidthWithGlyphSpacing(first,1);
 int other=TextLayout_ComputeWidthWithGlyphSpacing(second,1);
 if(width<other) width=other;
 int padded=width+0x18;
 window->layout->x=0x100-(padded+2);
 window->layout->width=padded;
 Graphics_PartitionObjectAndComputeVRAMBudget(window,allocation);
 if (Window_AllocateStagingBufferAndInitializeTextEntries(window)) {
 window->count=0;
 Window_DrawTiledFrameBorder(window);
 Text_RenderEntryAndStoreMeasuredRectangle(window,0,12,8,first,9,1);
 Text_RenderEntryAndStoreMeasuredRectangle(window,1,12,24,second,11,1);
 Graphics_StagePresentResourceRegion(window);
 if(window->staging) FreeVRAMStagingMemory(window->staging);
 result=0;
 } else result=1;
 }
 return result;
}
