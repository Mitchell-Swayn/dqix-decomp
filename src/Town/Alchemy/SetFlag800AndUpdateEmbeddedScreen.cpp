#include <globaldefs.h>
ARM
extern "C" void ItemDetail_DrawQuantityModeIcon(void*);
extern "C" void Graphics_RenderOrAppendSharedCanvasText(void*);
extern "C" void Graphics_ClearMainBG1Screen(void*);
// Original: arm9/ov006 @ 0x021570FC; symbol: SetFlag800AndUpdateEmbeddedScreen; size: 0x88.
// Updates bit800 of halfword1258 and calls the screen transition routines on changes.
extern "C" int SetFlag800AndUpdateEmbeddedScreen(char* self,int enabled) {
bool old=(*(unsigned short*)(self+0x1258)&0x800)!=0;
if(enabled)*(unsigned short*)(self+0x1258)|=0x800;else *(unsigned short*)(self+0x1258)&=~0x800;
if(!old && enabled){ItemDetail_DrawQuantityModeIcon(self+0xae4);Graphics_RenderOrAppendSharedCanvasText(self+0xae4);}
if(old && !enabled)Graphics_ClearMainBG1Screen(self+0xae4);
return old;
}
