#include <globaldefs.h>
ARM
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
extern "C" int AppendFormattedNumberAndText(char*,const char*,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
extern "C" int TextMarkup_AppendXPositionTag(char*,int);
// Original: arm9/ov002 @ 0x0215FBD4; symbol: func_ov002_0215fbd4; size: 0xEC.
// Centers the tactics heading and appends its six consecutive resource choices.
extern "C" void PartyMenu_AppendTacticsChoices(register char* self,register char* out,int decorated) {
 if(!out)return;
 short key=0x109c;
 int cursor=*(short*)(self+0x1c04);

 if(decorated)TextMarkup_AppendFrameTag(out,cursor,8,5,5,5);
 TextMarkup_AppendCursorTag(out,cursor);
 const char* heading=(const char*)ResourceStringTable_GetTextByKey(self+0x20,(void*)0x109a);
 int width=TextLayout_ComputeWidthWithGlyphSpacing(heading,0);
 TextMarkup_AppendXPositionTag(out,(120-width)>>1);
 AppendFormattedNumberAndText(out,heading,16);
 for(int i=0;i<6;i++) {
  const char* text=(const char*)ResourceStringTable_GetTextByKey(self+0x20,(void*)key++);
  Text_AppendFormattedIntegerAndStringFragment(out,i,text);
  if(i!=5)Text_AppendFormatString(out,*(const char**)(self+0x1bdc));
 }
}
