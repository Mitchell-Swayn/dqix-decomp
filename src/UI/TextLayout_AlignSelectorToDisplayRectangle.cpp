#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0206B7B0; symbol: TextLayout_AlignSelectorToDisplayRectangle; size: 0x54.
// Updates signed-halfword coordinates after local offsets, clamping wrapped negative results to zero.
extern "C" void TextLayout_AlignSelectorToDisplayRectangle(char* self) {
 int left=*(short*)(self+0x914);
 int width=*(short*)(self+0x918);
 int offsetX=*(short*)(self+0x148);
 int offsetY=*(short*)(self+0x14a);
 int top=*(short*)(self+0x916);
 short x=left+width-offsetX;
 if(x<0)x=0;
 short y=top-offsetY;
 if(y<0)y=0;
 *(short*)(self+0x144)=x;
 *(short*)(self+0x146)=y;
}
