#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned);
extern "C" int TextMarkup_AppendPaletteTag(char*,int);
extern "C" int TextMarkup_AppendXPositionTag(char*,int);
extern "C" const char* ResourceStringTable_GetTextByKey(void*,int);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" int Window_ReplaceCanvasTextById(void*,unsigned,void*,unsigned,unsigned char);
// Original: arm9/ov023 @ 0x021D9A6C; symbol: func_ov023_021d9a6c; size: 0x210.
extern "C" void CharacterCreation_RefreshAppearanceSummary(char* self){
 if(!(*(unsigned*)(self + 0xd9c)&0x100))return;
 if(*(signed char*)(self + 0xc58)>=11){*(unsigned*)(self + 0xd9c)&=~0x100;return;}
 unsigned char index=*(unsigned char*)(self + 0xda3);
 char* out=*(char**)(self + 0xf8);
 short offset=(short)((short)index*(short)100);
 short ids[7]={
 (short)(offset + 0x2710),
 (short)(*(unsigned char*)(self + 0xda4 + index) + 0x2af8),
 (short)(offset + 0x3a98 + *(unsigned char*)(self + 0xdac + index)),
 (short)(*(unsigned char*)(self + 0xdae + index) + 0x3e80),
 (short)(offset + 0x2ee0 + *(unsigned char*)(self + 0xda6 + index)),
 (short)(*(unsigned char*)(self + 0xdaa + index) + 0x36b0),
 (short)(*(unsigned char*)(self + 0xda8 + index) + 0x32c8)};
 memset(out,0,2400);
 for(int i=0;i<*(signed char*)(self + 0xda0 + *(unsigned char*)(self + 0xda3));i++){
  int color=15;if(i==*(signed char*)(self + 0xc58)-1)color=14;
  TextMarkup_AppendPaletteTag(out,color);
  if(i<7){
   int id=ids[i];
   const char* text=ResourceStringTable_GetTextByKey(self + 0xe0,id);
   int width=TextLayout_ComputeWidthWithGlyphSpacing(text,0);
   TextMarkup_AppendXPositionTag(out,50-width);
   text=ResourceStringTable_GetTextByKey(self + 0xe0,id);Text_AppendFormatString(out,text);
   text=ResourceStringTable_GetTextByKey(self + 0xe0,0x4273);Text_AppendFormatString(out,text);
  }else if(i==7){
   const char* text=(*(const char***)(self + 0xdb0))[*(unsigned char*)(self + 0xda3)];
   if(*text){int width=TextLayout_ComputeWidthWithGlyphSpacing(text,0);TextMarkup_AppendXPositionTag(out,50-width);Text_AppendFormatString(out,text);}
   else {text=ResourceStringTable_GetTextByKey(self + 0xe0,0x4274);Text_AppendFormatString(out,text);}
  }
 }
 Window_ReplaceCanvasTextById(self + 0x1f8,0,out,0,0);
 *(unsigned*)(self + 0xd9c)&=~0x100;
}
