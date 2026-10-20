#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
#pragma opt_propagation off
#pragma opt_common_subs off
typedef unsigned int undefined4;
extern "C" int BattleMenu_HasCommandBlockingStatus(char*);
extern "C" int Graphics_FormatPriorityFlaggedPartyLabel(char*,void*);
extern "C" void TextSprite_FormatAndUpdateTextReference(unsigned char*,const char*);
extern "C" unsigned GameObject_GetLinkedIndexedState(int);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
// Original: arm9/ov000 @ 0x02170FFC; symbol: BattleMenu_RefreshUncontrolledMemberLabel; size: 0xB0.
// Submits a formatted priority label, falling back to an indexed party-member label.
extern "C" void BattleMenu_RefreshUncontrolledMemberLabel(unsigned char* self) {
 if(self[0x24]&2)return;
 if(!self[0x87])return;
 if(BattleMenu_HasCommandBlockingStatus((char*)self)) {
  char buffer[128]={0};
  if(Graphics_FormatPriorityFlaggedPartyLabel((char*)self,buffer)>=0) {
   TextSprite_FormatAndUpdateTextReference(self+0x50,buffer);return;
  }
 }
 register int base=0x753e;
 GameObject* member=GameState::GetInstance()->GetPartyMemberByIndex(*(int*)(self+0x4c));
 if(!member)return;
 unsigned char* data=(unsigned char*)GameObject_GetLinkedIndexedState((int)member);
 short key=base+(signed char)*(unsigned*)(data+0x94c);
 TextSprite_FormatAndUpdateTextReference(self+0x50,(const char*)ResourceStringTable_GetTextByKey(*(void**)(self+4),(void*)key));
}
