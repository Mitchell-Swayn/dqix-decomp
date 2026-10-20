#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
extern "C" char* GameState_GetObjectWithFlag100(void*,int);
extern "C" int GameObject_HasLinkedStatusNibble(char*);
extern "C" void GameState_CollectPresentPartyMemberIndices(signed char*,signed char*);
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
extern "C" int AppendFormattedNumberAndText(char*,const char*,int);
extern "C" int Graphics_SelectObjectRatioColor(void*,int,int,int,int);
extern "C" int TextMarkup_AppendPaletteTag(char*,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" void* Text_LookupStandardString(unsigned);
// Original: arm9/ov002 @ 0x0215E250; symbol: func_ov002_0215e250; size: 0x1FC.
extern "C" void Text_AppendAvailablePartyMemberList(char* self,char* out,int cursorStyle) {
 if(!out)return;
 void* gs=_ZN9GameState11GetInstanceEv();
 short selected=*(short*)(self+0x1bf6);
 signed char indices[4];signed char count;
 GameState_CollectPresentPartyMemberIndices(indices,&count);
 signed char excluded=0;
 for(int i=0;i<count;i++) {
  char* obj=GameState_GetObjectWithFlag100(gs,indices[i]);
  if(obj && GameObject_HasLinkedStatusNibble(obj))excluded++;
 }
 count-=excluded;
 int index=0;
 if(cursorStyle)TextMarkup_AppendFrameTag(out,selected,8,5,5,5);
 TextMarkup_AppendCursorTag(out,selected);
 AppendFormattedNumberAndText(out,(const char*)ResourceStringTable_GetTextByKey(self+0x20,(void*)2),0x16);
 for(int line=0;line<count;line++) {
  if(!_ZN9GameState21GetPartyMemberByIndexEi(gs,indices[index]))continue;
  if(GameObject_HasLinkedStatusNibble(GameState_GetObjectWithFlag100(gs,indices[index]))) {
   for(int attempts=0;attempts<4;attempts++) {
    index=(index+1)%4;
    if(index==0)break;
    char* obj=GameState_GetObjectWithFlag100(gs,indices[index]);
    if(obj && !GameObject_HasLinkedStatusNibble(obj)) {
     _ZN9GameState21GetPartyMemberByIndexEi(gs,indices[index]);break;
    }
   }
  }
  TextMarkup_AppendPaletteTag(out,Graphics_SelectObjectRatioColor(self,indices[index],0,1,1));
  Text_AppendFormattedIntegerAndStringFragment(out,line,self+0x1ab0+indices[index]*0x3c);
  TextMarkup_AppendPaletteTag(out,15);
  Text_AppendFormatString(out,*(char**)(self+0x1bdc));
  index++;
 }
 Text_AppendFormattedIntegerAndStringFragment(out,count,(const char*)Text_LookupStandardString(0x1a));
}
