#include <globaldefs.h>
ARM
struct GameState; struct State;
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char* MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" int Inventory_CompactItemTypeGroup(char*,unsigned);
extern "C" void Menu_ResetItemListingSelection(void*);
extern "C" void Menu_QueueScriptEntry(State*,unsigned);
extern "C" void GameState_AppendValueAndSetNodeFlags(State*,int,int);
// Original: arm9/ov004 @ 0x0215B694; symbol: func_ov004_0215b694; size: 0x7C.
extern "C" int GameState_CompactEightSelectedSlotGroups(State* self) {
 char* list=(char*)GameState_GetIndexList((GameState*)_ZN9GameState11GetInstanceEv());
 if(!list) return 0;
 for(int i=0;i<8;i++) Inventory_CompactItemTypeGroup(list+0x1d4,(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[2]+i)[0x7c]);
 Menu_ResetItemListingSelection(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[2]);
 Menu_QueueScriptEntry(self,0x3a0);
 GameState_AppendValueAndSetNodeFlags(self,2,8);
 return 0;
}
