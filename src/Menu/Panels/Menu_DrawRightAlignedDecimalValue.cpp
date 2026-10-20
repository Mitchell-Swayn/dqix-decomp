#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#include <std_library_functions.h>
extern "C" void __clear(void*,unsigned);extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);extern "C" void TextCanvas_RenderStyledTextAndMeasure(void*,short,short,char*,unsigned char,unsigned char,short*,short*,int);extern "C" const char Menu_DrawRightAlignedDecimalValue_Format1F[];
// Original: arm9/ov023 @ 0x021DB3C0; symbol: DrawRightAlignedFormattedFloat; size: 0x9c.
extern "C" void Menu_DrawRightAlignedDecimalValue(void* self,int right,short y,float value,unsigned char style){
char text[64];short width,height;__clear(text,64);sprintf(text,Menu_DrawRightAlignedDecimalValue_Format1F,(double)value);int length=TextLayout_ComputeWidthWithGlyphSpacing(text,0);TextCanvas_RenderStyledTextAndMeasure(self,(short)(right-length),y,text,8,style,&width,&height,0);
}
