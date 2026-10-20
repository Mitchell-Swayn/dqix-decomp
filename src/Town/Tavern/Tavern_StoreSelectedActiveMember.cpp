#include <globaldefs.h>
ARM
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define I(p,o) (*(int*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))

#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* Zone3D_GetMainInstance();extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);extern "C" void _ZN13ZoneState2754C1Ev(void*);extern "C" void World_ResetZoneStateAndClearThreeWords(unsigned char*);extern "C" void World_ResetTemporaryZoneResourceState(void*);extern "C" int Inventory_AddGroupedItemQuantityAndCacheResult(char*,unsigned,unsigned,...);extern "C" unsigned TextContext_GetSharedInstance();extern "C" void* GameState_GetIndexList(void*);extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);extern "C" char* GameObject_GetLinkedIndexedState(void*);extern "C" void Field_ReturnMemberCarriedItemsToBag(int);extern "C" void Field_StoreMemberAndRemoveFromActiveParty(int,void*);extern "C" int SlotRecordTable_AssignUnusedSlotIDAndAppendRecord(void*,void*,unsigned char,unsigned char);struct SlotRecord{signed char id:6; signed char rest:2;unsigned char data[571];};
// Original: arm9/ov003 @ 0x02163E4C; symbol: Resource_AppendPartyMemberSlotRecordAcrossTwoPhases; size: 0x114.
extern "C" void Tavern_StoreSelectedActiveMember(char* self){if(B(self,0x4a4)==0){void* game=_ZN9GameState11GetInstanceEv();void* list=GameState_GetIndexList(game);void* actor=_ZN9GameState21GetPartyMemberByIndexEi(game,H(self,0x482));if(!actor){B(self,0x4a3)=16;return;}char* descriptor=GameObject_GetLinkedIndexedState(actor);if(!descriptor){B(self,0x4a3)=16;return;}H(self,0x484)=13;if(H(descriptor,0x454)>0)H(self,0x486)=14;Field_ReturnMemberCarriedItemsToBag(H(self,0x482));SlotRecord record;Field_StoreMemberAndRemoveFromActiveParty(H(self,0x482),&record);SlotRecordTable_AssignUnusedSlotIDAndAppendRecord(list,&record,0,0);H(self,0x480)=record.id;B(self,0x4a4)++;W(self,0x464)|=8;}else if(B(self,0x4a4)==1){H(self,0x484)=2;W(self,0x464)|=8;B(self,0x4a3)=1;B(self,0x4a4)=0;}}
