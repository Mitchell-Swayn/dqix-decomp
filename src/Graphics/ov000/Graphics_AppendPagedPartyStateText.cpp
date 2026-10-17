#include <globaldefs.h>
ARM
struct GameState; struct Object3D;
extern "C" void Selection_ComputeBoundedPageEntryRange(void*,int*,int*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" Object3D* _ZN9GameState21GetPartyMemberByIndexEi(GameState*,int);
extern "C" unsigned char* ReadWordFieldAtOffset150(void*);
extern "C" int IsStateAt118EqualTwo(void*);
extern "C" int AppendFiveFormattedArguments(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" void* ResolveIndexedRecordAndReturnSecondWord(void*,void*);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
// Original: arm9/ov000 @ 0x02179ED8; symbol: func_ov000_02179ed8; size: 0xBC.
extern "C" void Graphics_AppendPagedPartyStateText(unsigned char* self,unsigned char* entry,char* out) {
 if(entry && out) {
  int begin,end;
  Selection_ComputeBoundedPageEntryRange(self+0x1dc,&begin,&end);
  signed char first=begin;
  Object3D* member=_ZN9GameState21GetPartyMemberByIndexEi((GameState*)_ZN9GameState11GetInstanceEv(),*(int*)(entry+0x4c));
  if(member) {
   unsigned state=*(unsigned*)(ReadWordFieldAtOffset150(member)+0x950);
   int selected=*(signed char*)(entry+0x23);
   if(IsStateAt118EqualTwo(self)) AppendFiveFormattedArguments(out,selected-first,8,5,5,5);
   int cursor=selected-first;
   TextMarkup_AppendCursorTag(out,cursor);
   const char* text=(const char*)ResolveIndexedRecordAndReturnSecondWord(self+0xb8,(void*)(short)(state+0x63));
   Text_AppendFormattedIntegerAndStringFragment(out,cursor,text);
  }
 }
}
