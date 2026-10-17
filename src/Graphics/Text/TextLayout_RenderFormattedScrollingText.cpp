#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" {
extern char data_020ef6b6[];
void __clear(void *,unsigned);void BuildRecordsWithCumulativeHalfProductOffsets(void *,int,const short *,const short *,const short *,const short *);
void ClearTwoWordsAndFollowingByte(void *);void WriteFirstWordValue(void *,void *);void Object_SetWord4AndByte8(void *,void *,int);void func_0205b234(void *,int,int,const char *,unsigned char,unsigned char);
struct Text {unsigned words[3];};struct Glyphs {unsigned char bytes[252];};
// Original: arm9/main @ 0x02023218; symbol: func_02023218; size: 0x118.
void TextLayout_RenderFormattedScrollingText(unsigned char *p,unsigned char *base,int offset) {
    Glyphs entries;char text[256];short x[21],y[21],width[21],height[21];Text transfer;
    __clear(y,42);for(int i=0;i<21;i++){x[i]=i<<3;width[i]=8;height[i]=16;}
    BuildRecordsWithCumulativeHalfProductOffsets(&entries,21,x,y,width,height);
    int position;if(*(int *)(p+0xbe4)>152)position=-*(int *)(p+0xbe8);else position=(152-*(int *)(p+0xbe4))>>1;
    ClearTwoWordsAndFollowingByte(&transfer);WriteFirstWordValue(&transfer,base+offset);Object_SetWord4AndByte8(&transfer,&entries,21);
    __clear(text,256);sprintf(text,data_020ef6b6,p+0x5b4,p+0x5f4);func_0205b234(&transfer,(short)position,3,text,15,0);
}
}
