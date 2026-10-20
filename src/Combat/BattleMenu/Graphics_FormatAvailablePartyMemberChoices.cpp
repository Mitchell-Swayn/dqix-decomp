#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int BattleMenu_HasTouchSelectionChanged(char*);
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" char* GameState_GetIndexList(void*);
extern "C" char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);
extern "C" void __clear(void*,unsigned);
extern "C" int BattleHud_ClassifyHealthRatio(char*);
extern "C" int TextMarkup_AppendPaletteTagForType(char*,unsigned);
extern "C" void TextSprite_DecodeCachedText(unsigned char*,unsigned);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int TextMarkup_AppendXPositionTag(char*,int);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" void* Text_LookupStandardString(unsigned);
// Original: arm9/ov000 @ 0x021777E4; symbol: func_ov000_021777e4; size: 0x1D0.
extern "C" void Graphics_FormatAvailablePartyMemberChoices(char* self,char* out){
 if(!out)return;
 void* state=_ZN9GameState11GetInstanceEv();
 int cursor=*(signed char*)(self+0x1d6b);
 char* record;int count=0;
 unsigned char i;int kind,index;
 if(BattleMenu_HasTouchSelectionChanged(self))TextMarkup_AppendFrameTag(out,cursor,8,5,5,5);
 TextMarkup_AppendCursorTag(out,cursor);
 char* list=GameState_GetIndexList(state);
 char* records=self+0x158; i=0;records+=0x800;
 for(;i<*(unsigned char*)(list+0xf7c);i++){
  record=records+*(signed char*)(self+0x6c+i)*0x448;
  index=*(int*)(record+0x4c);
  int valid;
  if(index>=0 && index<=3)valid=1;else valid=0;
  if(!valid)continue;
  if(*(unsigned char*)(record+0x24)&2)continue;
  char* object=_ZN9GameState21GetPartyMemberByIndexEi(state,index);if(!object)return;
  unsigned char* data=GameObject_GetLinkedIndexedState(object);
  char buffer[128];__clear(buffer,128);
  kind=(signed char)*(int*)(data+0x94c);
  TextMarkup_AppendPaletteTagForType(out,BattleHud_ClassifyHealthRatio(record));
  TextSprite_DecodeCachedText((unsigned char*)record+0x68,(unsigned)buffer);
  Text_AppendFormattedIntegerAndStringFragment(out,count,buffer);
  TextMarkup_AppendXPositionTag(out,78);
  TextMarkup_AppendPaletteTagForType(out,0);
  const char* name=(const char*)ResourceStringTable_GetTextByKey(self+0xb8,(void*)(short)(kind+0x753e));
  Text_AppendFormatString(out,name);
  const char* separator=(const char*)ResourceStringTable_GetTextByKey(self+0xb8,0);
  Text_AppendFormatString(out,separator);
  *(unsigned char*)(self+0x1d74+count)=index;
  count++;
 }
 *(unsigned char*)(self+0x1d74+count)=4;
 const char* text=(const char*)Text_LookupStandardString(26);
 Text_AppendFormattedIntegerAndStringFragment(out,count,text);
}
