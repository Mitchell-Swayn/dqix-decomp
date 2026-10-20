#include <globaldefs.h>
ARM
extern "C" void __clear(void*,unsigned);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendPaletteTag(char*,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" void Selection_ComputeBoundedPageEntryRange(void*,int*,int*);
extern "C" void Text_FormatAndConditionallyUppercaseOutput(const char*,char*,int);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
extern "C" void String_ReplaceBracketedNamesByRowColumnTable(const signed char*,signed char*,int,unsigned,unsigned,int);
extern "C" void* BattleMenu_GetAbilityChoice(void*,int);
extern "C" int BattleMenu_HasTouchSelectionChanged(void*);
extern "C" int BattleMenu_IsSkillEquipmentCompatible(void*,int);
// Original: arm9/ov000 @ 0x0217936C; symbol: func_ov000_0217936c; size: 0x160.
extern "C" void Text_AppendSelectionPageEntries(char* self,char* records,char* out) {
 if(!records||!out)return;
 int first,last;
 Selection_ComputeBoundedPageEntryRange(self+0x1dc,&first,&last);
 short begin=(short)first;
 short end=(short)last;
 short selected=*(short*)(records+0x1e);
 if(BattleMenu_HasTouchSelectionChanged(self))TextMarkup_AppendFrameTag(out,selected-begin,8,5,5,5);
 TextMarkup_AppendCursorTag(out,selected-begin);
 for(short i=begin;i<end;i++) {
  char* record=(char*)BattleMenu_GetAbilityChoice(records,i);
  if(record) {
   int color=3;
   if(BattleMenu_IsSkillEquipmentCompatible(records,i))color=15;
   TextMarkup_AppendPaletteTag(out,color);
   char expanded[128]; char formatted[128];
   __clear(expanded,128); __clear(formatted,128);
   String_ReplaceBracketedNamesByRowColumnTable(*(signed char**)record,(signed char*)expanded,1,0,0,0);
   Text_FormatAndConditionallyUppercaseOutput(expanded,formatted,0);
   Text_AppendFormattedIntegerAndStringFragment(out,i-begin,expanded);
   if(i!=end-1)Text_AppendFormatString(out,(char*)ResourceStringTable_GetTextByKey(self+0xb8,0));
  }
 }
}
