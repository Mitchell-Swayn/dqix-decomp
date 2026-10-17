#include <globaldefs.h>
ARM
extern "C" char data_020f0518[];extern "C" int _s32_div_f(int,int);extern "C" int Text_FormatAbsoluteIntegerAndMeasureWidth(unsigned char,int);extern "C" void __clear(void*,unsigned);extern "C" int sprintf(char*,const char*,...);extern "C" void func_0205b234(void*,int,int,const char*,unsigned char,unsigned char);
// Original: arm9/main @ 0x0205B674; symbol: func_0205b674; size: 0xC0.
extern "C" void DrawAlignedFormattedInteger(unsigned* p,int x,int y,int value,unsigned char a,unsigned char width,unsigned char align,unsigned char mode){char text[12];if(!p[0]||!p[1])return;int n=value;do{n=_s32_div_f(n,10);}while(n);int size=Text_FormatAbsoluteIntegerAndMeasureWidth(mode,value);if(align==1)x=(short)(x+(short)(width*8-size));__clear(text,10);sprintf(text,data_020f0518,value);func_0205b234(p,x,y,text,a,mode);}
