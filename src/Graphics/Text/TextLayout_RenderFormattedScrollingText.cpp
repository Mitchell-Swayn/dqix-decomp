#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" {
extern char TextLayout_RenderFormattedScrollingText_FormatSS[];
void __clear(void *,unsigned);void TextCanvas_BuildPackedRegionDescriptors(void *,int,const short *,const short *,const short *,const short *);
void TextCanvas_InitializeRegionCanvas(void *);void TextCanvas_SetPixelBuffer(void *,void *);void TextCanvas_SetRegions(void *,void *,int);void TextCanvas_DrawStringAndMeasureAdvance(void *,int,int,const char *,unsigned char,unsigned char);
struct Text {unsigned words[3];};struct Glyphs {unsigned char bytes[252];};
// Original: arm9/main @ 0x02023218; symbol: func_02023218; size: 0x118.
void TextLayout_RenderFormattedScrollingText(unsigned char *p,unsigned char *base,int offset) {
    Glyphs entries;char text[256];short x[21],y[21],width[21],height[21];Text transfer;
    __clear(y,42);for(int i=0;i<21;i++){x[i]=i<<3;width[i]=8;height[i]=16;}
    TextCanvas_BuildPackedRegionDescriptors(&entries,21,x,y,width,height);
    int position;if(*(int *)(p+0xbe4)>152)position=-*(int *)(p+0xbe8);else position=(152-*(int *)(p+0xbe4))>>1;
    TextCanvas_InitializeRegionCanvas(&transfer);TextCanvas_SetPixelBuffer(&transfer,base+offset);TextCanvas_SetRegions(&transfer,&entries,21);
    __clear(text,256);sprintf(text,TextLayout_RenderFormattedScrollingText_FormatSS,p+0x5b4,p+0x5f4);TextCanvas_DrawStringAndMeasureAdvance(&transfer,(short)position,3,text,15,0);
}
}
