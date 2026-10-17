#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" void __clear(void*,unsigned);extern "C" unsigned TestValueEqualsTwelve(unsigned char);extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(void*,unsigned);extern "C" void func_0204f41c(void*,int,int,void*,unsigned,unsigned,void*,void*,unsigned);extern "C" char data_020f02f5[],data_020f02fc[],data_020f0300[];
// Original: arm9/main @ 0x0204F7E8; symbol: func_0204f7e8; size: 0x12C.
extern "C" void TextCanvas_FormatAndRenderSignedPaddedInteger(void* p,int x,int y,int number,unsigned char a,unsigned char b,void* c,void* d,unsigned char right,unsigned char width,unsigned char sign,unsigned char padded){
 int quotient=number;do{quotient/=10;}while(quotient);char text[64],format[8];__clear(text,64);if(padded){__clear(format,8);sprintf(format,data_020f02f5,(unsigned)width);sprintf(text,format,number);}else if(sign&&number>0)sprintf(text,data_020f02fc,number);else sprintf(text,data_020f0300,number);
 unsigned font=TestValueEqualsTwelve(a);if(right)x=(short)(x-TextLayout_ComputeWidthWithGlyphSpacing(text,font));func_0204f41c(p,x,y,text,a,b,c,d,font);
}
