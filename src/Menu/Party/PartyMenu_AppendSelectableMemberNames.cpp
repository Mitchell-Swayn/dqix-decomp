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
extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
// Original: arm9/ov002 @ 0x0215C348; symbol: func_ov002_0215c348; size: 0x12C.
// Appends selectable party member names, skipping missing member records.
extern "C" void PartyMenu_AppendSelectableMemberNames(char* self,char* out,int decorated) {
 void* state=_ZN9GameState11GetInstanceEv();
 int cursor=*(short*)(self+0x1be2);
 int row=0;
 if(decorated)TextMarkup_AppendFrameTag(out,cursor,8,5,5,5);
 TextMarkup_AppendCursorTag(out,cursor);
 AppendFormattedNumberAndText(out,(const char*)ResourceStringTable_GetTextByKey(self+0x20,(void*)0x5dc),22);
 unsigned char count=*(unsigned char*)(self+0x1c73);
 unsigned char* indices=(unsigned char*)(self+0x1c6e);
 for(unsigned char i=0;i<count;i++) {
  int index=indices[i];
  char* member=(char*)_ZN9GameState21GetPartyMemberByIndexEi(state,index);
  if(member) {
   TextMarkup_AppendPaletteTag(out,Graphics_SelectObjectRatioColor(self,index,0,1,1));
   Text_AppendFormattedIntegerAndStringFragment(out,row,*(const char**)(member+0x134));
   TextMarkup_AppendPaletteTag(out,15);
   row++;
   if(i!=count-1)Text_AppendFormatString(out,*(const char**)(self+0x1bdc));
  }
 }
}
