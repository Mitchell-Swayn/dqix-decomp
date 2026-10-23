#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
extern "C" int AppendFormattedNumberAndText(char*,const char*,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" int TextMarkup_AppendPaletteTag(char*,int);
extern "C" int Graphics_SelectObjectRatioColor(char*,int,int,int,unsigned char);
// Original: arm9/ov002 @ 0x0215D0E8; symbol: func_ov002_0215d0e8; size: 0x12C.
// Appends colored target names using the active action's target index list.
extern "C" void PartyMenu_AppendActionTargetNames(char* self,char* out,int decorated) {
 if(!out)return;
 int cursor=*(short*)(self+0x1bec);
 _ZN9GameState11GetInstanceEv();
 if(decorated)TextMarkup_AppendFrameTag(out,cursor,8,5,5,5);
 TextMarkup_AppendCursorTag(out,cursor);
 AppendFormattedNumberAndText(out,(const char*)ResourceStringTable_GetTextByKey(self+0x20,(void*)0x514),16);
 int count=*(unsigned char*)(self+0x1c6d);
 unsigned char* indices=(unsigned char*)(self+0x1c68);
 if(*(unsigned char*)(self+0x1c84)==7) {
  count=*(unsigned char*)(self+0x1c73);
  indices=(unsigned char*)(self+0x1c6e);
 }
 char* names=self+0xab0; names+=0x1000;
 for(int i=0;i<count;i++) {
  int index=indices[i];
  TextMarkup_AppendPaletteTag(out,Graphics_SelectObjectRatioColor(self,index,1,1,1));
  Text_AppendFormattedIntegerAndStringFragment(out,i,names+index*60);
  TextMarkup_AppendPaletteTag(out,15);
  if(i!=count-1)Text_AppendFormatString(out,*(const char**)(self+0x1bdc));
 }
}
