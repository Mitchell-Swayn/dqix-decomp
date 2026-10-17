#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" {void __clear(void*,int);extern char data_020f120d[],data_020f1212[],data_020f1217[];int TextLayout_ComputeWidthWithGlyphSpacing(char*,int);void func_0204f41c(void*,short,int,char*,int,unsigned char,short*,short*,int);
// Original: arm9/main @ 0x0208D42C; symbol: func_0208d42c; size: 0xF0.
void Text_FormatAndRenderStyledIntegerAtCoordinates(int unused,void* object,int x,int y,int value,unsigned char style,unsigned char mode,unsigned char centered,unsigned char tagged){if(!object)return;char text[8];short b,a;int offset=0;__clear(text,8);if(tagged){if(mode==2)sprintf(text,data_020f120d,value);else sprintf(text,data_020f1212,value);}else sprintf(text,data_020f1217,value);if(centered)offset=(short)-TextLayout_ComputeWidthWithGlyphSpacing(text,0);func_0204f41c(object,(short)(x+offset),y,text,8,style,&b,&a,0);}}
