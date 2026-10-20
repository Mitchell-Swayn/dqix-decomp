#include <globaldefs.h>
ARM
#pragma always_inline on
struct GameState;
struct MemberRecord { char pad[0x87]; unsigned char listed; char tail[0x3c0]; };
struct RecordOwner { char pad[0x958]; MemberRecord records[1]; };
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" void InitializeObjectAndConfigureSelectionIfPresent(void*,int);
extern "C" int BattleMenu_HasCommandBlockingStatus(char*);
extern "C" void GameState_RefreshFourSlotLinkedObjectValues(void*);
static inline MemberRecord* MemberAt(MemberRecord* array,int index) { return array+index; }
// Original: arm9/ov000 @ 0x0217FA60; symbol: func_ov000_0217fa60; size: 0x138.
extern "C" void GameState_ProcessEligibleListedMemberRecords(char* self) {
 GameState_RefreshFourSlotLinkedObjectValues(self);
 for(unsigned char i=0;i<4;i++) {
  MemberAt(((RecordOwner*)self)->records,*(signed char*)(self+0x6c+i))->listed=0;
 }
 char* list=(char*)GameState_GetIndexList((GameState*)_ZN9GameState11GetInstanceEv());
 for(unsigned char i=0;i<*(unsigned char*)(list+0xf7c);i++) {
  MemberAt(((RecordOwner*)self)->records,*(unsigned char*)(list+0xf78+i))->listed=1;
 }
 char* record;
 int chosen=-1;
 for(int i=0;i<4;i++) {
  record=self+0x958+*(signed char*)(self+0x6c+i)*0x448;
  if(*(int*)(record+0x4c)>=0 && *(unsigned char*)(record+0x87) && !BattleMenu_HasCommandBlockingStatus(record) && *(unsigned char*)(record+0x445)) {
   InitializeObjectAndConfigureSelectionIfPresent(record,0);
   *(unsigned char*)(record+0x24)&=~4;
   if(chosen<0) chosen=*(int*)(record+0x4c);
  }
 }
 int valid;
 if(chosen>=0 && chosen<=3) valid=1;else valid=0;
 if(valid) *(int*)(self+0x17c)=chosen;
}
