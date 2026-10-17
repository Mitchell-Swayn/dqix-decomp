#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned);
extern "C" int Text_AppendFormattedIntegerFragmentAt020EFF74(char*,int);
extern "C" int Text_AppendFormattedIntegerFragmentAt020EFE78(char*,int);
extern "C" const char* ResolveIndexedRecordAndReturnSecondWord(void*,int);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
extern "C" int AppendFormatText(char*,const char*);
extern "C" int LoadMatchingReadyRecordAndRefreshOwner(void*,unsigned,void*,unsigned,unsigned char);
// Original: arm9/ov023 @ 0x021D9A6C; symbol: func_ov023_021d9a6c; size: 0x210.
extern "C" void Graphics_RebuildAlignedRecordDetailText(char* self){
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
  Text_AppendFormattedIntegerFragmentAt020EFF74(out,color);
  if(i<7){
   int id=ids[i];
   const char* text=ResolveIndexedRecordAndReturnSecondWord(self + 0xe0,id);
   int width=TextLayout_ComputeWidthWithGlyphSpacing(text,0);
   Text_AppendFormattedIntegerFragmentAt020EFE78(out,50-width);
   text=ResolveIndexedRecordAndReturnSecondWord(self + 0xe0,id);AppendFormatText(out,text);
   text=ResolveIndexedRecordAndReturnSecondWord(self + 0xe0,0x4273);AppendFormatText(out,text);
  }else if(i==7){
   const char* text=(*(const char***)(self + 0xdb0))[*(unsigned char*)(self + 0xda3)];
   if(*text){int width=TextLayout_ComputeWidthWithGlyphSpacing(text,0);Text_AppendFormattedIntegerFragmentAt020EFE78(out,50-width);AppendFormatText(out,text);}
   else {text=ResolveIndexedRecordAndReturnSecondWord(self + 0xe0,0x4274);AppendFormatText(out,text);}
  }
 }
 LoadMatchingReadyRecordAndRefreshOwner(self + 0x1f8,0,out,0,0);
 *(unsigned*)(self + 0xd9c)&=~0x100;
}
