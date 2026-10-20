#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
extern "C" void* Network_GetConnectionManager();
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendPaletteTag(char*,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int AppendFormattedNumberAndText(char*,const char*,int);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
extern "C" int Graphics_SelectObjectRatioColor(void*,int,int,int,int);
// Original: arm9/ov002 @ 0x0215C72C; symbol: func_ov002_0215c72c; size: 0x178.
extern "C" void Graphics_AppendPartyMemberListText(char* p,char* out,int decorated) {
 char* base1c; char* base1k; signed char* list; int n; int i; char* member;
 if(!out) return;
 Network_GetConnectionManager();
 void* state=_ZN9GameState11GetInstanceEv();
 int cursor=*(short*)(p+0x1be6);
 n=0;
 if(decorated) TextMarkup_AppendFrameTag(out,cursor,8,5,5,5);
 TextMarkup_AppendCursorTag(out,cursor);
 AppendFormattedNumberAndText(out,(const char*)ResourceStringTable_GetTextByKey(p+0x20,(void*)0x44c),0x18);
 for(i=0;i<*(signed char*)(p+0x1c73);i++) {
  member=(char*)_ZN9GameState21GetPartyMemberByIndexEi(state,*(signed char*)(p+0x1c6e + i));
  if(member) {
   TextMarkup_AppendPaletteTag(out,Graphics_SelectObjectRatioColor(p,*(signed char*)(p+0x1c6e + i),0,1,1));
   Text_AppendFormattedIntegerAndStringFragment(out,n,*(const char**)(member+0x134));
   TextMarkup_AppendPaletteTag(out,15);
   Text_AppendFormatString(out,*(const char**)(p+0x1bdc));
   n++;
  }
 }
 Text_AppendFormattedIntegerAndStringFragment(out,n,(const char*)ResourceStringTable_GetTextByKey(p+0x20,(void*)0x44d));
 if(!*(unsigned char*)(p+0x2485)) {
  Text_AppendFormatString(out,*(const char**)(p+0x1bdc));
  Text_AppendFormattedIntegerAndStringFragment(out,n+1,(const char*)ResourceStringTable_GetTextByKey(p+0x20,(void*)0x44e));
 }
}
