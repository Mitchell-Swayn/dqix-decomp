#include <globaldefs.h>
#include <GameState/GameState.h>
#pragma always_inline on
struct Item {unsigned char prefix[4];const signed char* text;unsigned char pad[14];short action,count;};
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
extern "C" void TextSprite_FormatAndUpdateTextReference(unsigned char*,const char*);
extern "C" void* ActionData_GetGlobalTables();
extern "C" void* ActionData_FindDefinitionInPrimaryOrSecondaryTable(char*,int);
extern "C" int BattleMenu_ResolveActionTargetSelectionState(char*,char*);
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" void* __clear(void*,unsigned);
extern "C" void String_ReplaceBracketedNamesByRowColumnTable(const signed char*,signed char*,int,unsigned,unsigned,int);
extern "C" void Text_FormatAndConditionallyUppercaseOutput(const char*,char*,int);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void TextMarkup_ExpandAndWrapText(void*,int,void*,void*,int,int,unsigned);
static inline void ShowUnavailable(unsigned char* self){
 ++*(signed char*)(self+0x18);
 (self+*(signed char*)(self+0x18))[0x10]=14;
 self[0x1d]=0;
 TextSprite_FormatAndUpdateTextReference(self+0x50,(const char*)ResourceStringTable_GetTextByKey(*(void**)(self+4),(void*)5));
}
// Original: arm9/ov000 @ 0x02171E60; symbol: func_ov000_02171e60; size: 0x19C.
// Validates the selected inventory action, advances target selection and formats its description.
extern "C" void BattleMenu_ConfirmSelectedItem(void* object){
 unsigned char* self=(unsigned char*)object;
 Item* item=*(Item**)(self+0x3f0+*(signed char*)(self+0x22)*4);
 if(item->count<=0){ShowUnavailable(self);return;}
 char* definition=(char*)ActionData_FindDefinitionInPrimaryOrSecondaryTable((char*)ActionData_GetGlobalTables(),item->action);
 if(!definition){ShowUnavailable(self);return;}
 ++*(signed char*)(self+0x18);
 (self+*(signed char*)(self+0x18))[0x10]=BattleMenu_ResolveActionTargetSelectionState(definition,(char*)self);
 if(*(signed char*)(self+0x10+*(signed char*)(self+0x18))==19){
  self[0x21]=0;self[0x2e]=*(int*)(self+0x4c);
  unsigned char* roster=(unsigned char*)GameState_GetIndexList(GameState::GetInstance());
  if(roster[0xf7c]==1)(self+*(signed char*)(self+0x18))[0x10]=100;
 }
 signed char expanded[128];char formatted[128];
 __clear(expanded,128);__clear(formatted,128);
 String_ReplaceBracketedNamesByRowColumnTable(item->text,expanded,1,0,0,0);
 Text_FormatAndConditionallyUppercaseOutput((char*)expanded,formatted,0);
 TextMarkup_ExpandAndWrapText((void*)TextContext_GetSharedInstance(),10,formatted,expanded,256,0,0);
 TextSprite_FormatAndUpdateTextReference(self+0x50,(char*)expanded);
}
