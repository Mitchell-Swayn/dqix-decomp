#include <globaldefs.h>
ARM
#pragma opt_common_subs off
extern "C" void* _ZN9GameState11GetInstanceEv();
struct GameResources;
extern "C" GameResources* GameResources_GetInstance();
extern "C" void* GameState_GetIndexList(void*);
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" char* GameObject_ResolveLinkedStatsOrNull(char**);
extern "C" int GameObject_TestAndClearStatusMask(unsigned**,unsigned);
extern "C" int Inventory_AddItemQuantityToTypeGroup(void*,unsigned,int,unsigned);
extern "C" void Field_QueuePartyMemberEquipmentRefresh(void*,int,int,int,int);
// Original data: arm9/main @ 0x20e8854; symbol: data_020e8854.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000100040005000600070008000900.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e8864; symbol: data_020e8864.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000010002000300050006000700080009000a00.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" short GameStateReturnEightEquipmentItemsToInventoryAndClearSlots_UnknownRoleInitializedBytes[],GameStateReturnEightEquipmentItemsToInventoryAndClearSlots_UnknownRoleInitializedBytes_Variant2[];

#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct ItemFlags {unsigned type:4,rest:28;};
// Original: arm9/main @ 0x020732CC; symbol: GameState_ReturnEightEquipmentItemsToInventoryAndClearSlots; size: 0xFC.
extern "C" void GameState_ReturnEightEquipmentItemsToInventoryAndClearSlots(int index){void* game=_ZN9GameState11GetInstanceEv();void* resources=GameResources_GetInstance();char* list=(char*)GameState_GetIndexList(game);char* object=(char*)GameState_GetObjectWithFlag100(game,index);if(!object)return;for(int i=0;i<8;++i){char* items;char* record;int slot=GameStateReturnEightEquipmentItemsToInventoryAndClearSlots_UnknownRoleInitializedBytes[i];record=P(object,0x150)+0x194+(unsigned char)GameStateReturnEightEquipmentItemsToInventoryAndClearSlots_UnknownRoleInitializedBytes_Variant2[slot]*32;items=GameObject_ResolveLinkedStatsOrNull((char**)object);if(items&&record){if(S(items,slot*2)>0){GameObject_TestAndClearStatusMask((unsigned**)object,4);Inventory_AddItemQuantityToTypeGroup(list+0x1d4,S(items,slot*2),1,((ItemFlags*)(record+8))->type);}S(items,slot*2)=-1;}}Field_QueuePartyMemberEquipmentRefresh(resources,index,0,0,0);}