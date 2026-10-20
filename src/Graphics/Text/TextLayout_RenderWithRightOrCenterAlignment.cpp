#include <globaldefs.h>
ARM
#pragma optimize_for_size off
struct Direction {signed char x,y;};
extern "C" int Font_MeasureTextHeightWithReader(unsigned,unsigned,unsigned);
extern "C" void Graphics_RenderAlignedTextLinesInDirection(unsigned*,int,int,unsigned,unsigned,unsigned,unsigned,Direction);
// Original: arm9/main @ 0x020B26E8; symbol: func_020b26e8; size: 0xE0.
extern "C" void TextLayout_RenderWithRightOrCenterAlignment(unsigned* p,int x,int y,unsigned value,int width,unsigned extra,unsigned flags,unsigned data,Direction direction){
    if(flags&0x100){
        int length=Font_MeasureTextHeightWithReader(p[1],p[3],data);
        int difference=width-length;
        x+=difference*-direction.y;y+=difference*direction.x;
    }else if(flags&0x80){
        int length=Font_MeasureTextHeightWithReader(p[1],p[3],data);
        int difference=(width+1)/2-(length+1)/2;
        x+=difference*-direction.y;y+=difference*direction.x;
    }
    Graphics_RenderAlignedTextLinesInDirection(p,x,y,value,extra,flags,data,direction);
}
