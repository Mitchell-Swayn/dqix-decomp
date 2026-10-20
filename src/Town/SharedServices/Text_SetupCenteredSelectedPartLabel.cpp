#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
extern "C" void TextCanvas_SetEntryTextAlignmentMode(char*,int,int);
extern "C" void TextCanvas_GetEntryLocalPosition(char*,int,short*,short*);
extern "C" void TextCanvas_SetEntryLocalPosition(char*,int,int,int);
extern "C" void TextCanvas_HideEntry(unsigned char*,int);
extern "C" void TextCanvas_ShowEntry(unsigned char*,int);
extern "C" void TextCanvas_SetEntryTextColor(char*,int,unsigned);
extern "C" void TextCanvas_SetEntryTextPointer(char*,int,int);
extern "C" void TextCanvas_SetEntryNumericValue(char*,int,int);
extern "C" void* TextCanvas_GetEntryMessageText(char*,int);
extern "C" void TextCanvas_SetEntryMessageKey(char*,int,short);
extern "C" void* Text_LookupStandardString(unsigned);
// Original: arm9/ov003 @ 0x02167E28; symbol: func_ov003_02167e28; size: 0x17C.
extern "C" void Text_SetupCenteredSelectedPartLabel(char* self,int text,int value,int label,unsigned char badge,int first,int second) {
 char* p=*(char**)(self+0x10);
 TextCanvas_SetEntryTextPointer(p,3,(int)Text_LookupStandardString(0x3f3));
 TextCanvas_SetEntryTextAlignmentMode(p,3,1);
 TextCanvas_SetEntryTextPointer(p,0,text);
 TextCanvas_SetEntryTextAlignmentMode(p,0,1);
 TextCanvas_SetEntryMessageKey(p,1,(short)value);
 TextCanvas_SetEntryNumericValue(p,5,first);
 TextCanvas_SetEntryNumericValue(p,6,second);
 TextCanvas_SetEntryMessageKey(p,2,(short)(label+2));
 int width=TextLayout_ComputeWidthWithGlyphSpacing((const char*)TextCanvas_GetEntryMessageText(p,2),0);
 short x,y;
 TextCanvas_GetEntryLocalPosition(p,2,&x,&y);
 x=0x40;
 x-=(width>>1);
 TextCanvas_SetEntryLocalPosition(p,2,x,y);
 TextCanvas_HideEntry((unsigned char*)p,0x2c);
 if(!badge)return;
 TextCanvas_ShowEntry((unsigned char*)p,0x2c);
 TextCanvas_SetEntryLocalPosition(p,0x2c,(short)(x+width+1),y);
 TextCanvas_SetEntryMessageKey(p,0x2c,(short)(badge+0x1c));
 unsigned nibble=5;
 if(badge==10)nibble=13;
 TextCanvas_SetEntryTextColor(p,0x2c,nibble);
}
