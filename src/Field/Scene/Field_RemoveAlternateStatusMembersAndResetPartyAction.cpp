#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameResources_GetInstance();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" int GameObject_HasLinkedStatusNibble(char*);
extern "C" void Field_RemovePartyMemberAndEquipment(void*,int);
extern "C" void GameState_ClearObjectByIndex(void*,unsigned);
extern "C" char* GameState_GetIndexList(void*);
// Original: arm9/ov017 @ 0x02191484; symbol: UpdateFlaggedPartySlotsAndClearCompletion; size: 0x84.
// Updates flagged party slots then clears object CE and two completion bytes.
extern "C" void Field_RemoveAlternateStatusMembersAndResetPartyAction(char* p) {
 void* state=_ZN9GameState11GetInstanceEv();void* resources=GameResources_GetInstance();
 for(int i=0;i<4;++i) { char* obj=(char*)GameState_GetObjectWithFlag100(state,i);if(obj && GameObject_HasLinkedStatusNibble(obj)) Field_RemovePartyMemberAndEquipment(resources,i); }
 GameState_ClearObjectByIndex(state,0xce);
 GameState_GetIndexList(state)[0xf7d]=0;
 (*(char**)(p+0x3ba0))[11]=0;
}
