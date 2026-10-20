#include <globaldefs.h>
ARM
extern "C" int Menu_GetInventoryRecordSourceByKey(void*,int);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void _ZN13ZoneState2754C1Ev(void*);
extern "C" void World_ResetZoneStateAndClearThreeWords(unsigned char*);
extern "C" void PlacementAllocator_ApplyCountByRecordKindAndAvailableActors(void*,int,int,int);
extern "C" void Menu_ResetPendingItemTransaction(short*);
extern "C" void Menu_QueueScriptEntry(void*,unsigned);
// Original: arm9/ov004 @ 0x0215B740; symbol: ApplySavedPlacementRecordAndResetIt; size: 0x88.
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int Menu_ReturnPendingListingItemsToInventory(void *self) {
 char *state=(char*)_ZN9GameState11GetInstanceEv()+0x5e6c;
 int value=Menu_GetInventoryRecordSourceByKey(self,5);
 unsigned char local[56];
 _ZN13SafeAllocator21ResetAllocatorPointerEv(local);_ZN13ZoneState2754C1Ev(local+20);
 World_ResetZoneStateAndClearThreeWords(local);World_ResetZoneStateAndClearThreeWords(local);
 *(int*)(local+44)=value;
 PlacementAllocator_ApplyCountByRecordKindAndAvailableActors(local,*(short*)(state+0xf8),(signed char)*(unsigned short*)(state+0xfa),0);
 Menu_ResetPendingItemTransaction((short*)(state+0xf8));Menu_QueueScriptEntry(self,932);return 0;
}
