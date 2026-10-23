#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov003 @ 0x217f494; symbol: data_ov003_0217f494.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000100040005000600070008000900ffff.
// Observed span: 18 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
// Original data: arm9/ov003 @ 0x217f4a6; symbol: data_ov003_0217f4a6.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 02000300050006000400000001000700ffff.
// Observed span: 18 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
struct NineShorts{short entries[9];};extern "C" {void* _ZN9GameState11GetInstanceEv();unsigned char* GameState_GetIndexList(void*);unsigned char* Tavern_FindStoredCharacterBySlotId(void*,int);int Inventory_AddItemQuantityToTypeGroup(void*,unsigned,int,unsigned);int PartyRoster_RemoveCharacterBySlotIdAndCompact(void*,int);extern NineShorts TavernReturnEquipmentAndDismissStoredCharacter_UnknownRoleInitializedBytes,TavernReturnEquipmentAndDismissStoredCharacter_UnknownRoleInitializedBytes_Variant2;}
// Original: arm9/ov003 @ 0x021668FC; symbol: Inventory_AddMappedRecordItemsAndFinalize; size: 0xf4.
// Adds nonnegative mapped record items to inventory with a shared type mapping.
extern "C" void Tavern_ReturnEquipmentAndDismissStoredCharacter(unsigned char* self){if(H(self,0x480)<0)return;unsigned char* inventory=GameState_GetIndexList(_ZN9GameState11GetInstanceEv());unsigned char* record=Tavern_FindStoredCharacterBySlotId(self,H(self,0x480));if(!record)return;short* items=(short*)(record+0x160);NineShorts indices=TavernReturnEquipmentAndDismissStoredCharacter_UnknownRoleInitializedBytes;NineShorts types=TavernReturnEquipmentAndDismissStoredCharacter_UnknownRoleInitializedBytes_Variant2;for(unsigned char i=0;indices.entries[i]>=0;++i){int item=items[indices.entries[i]];if(item>=0)Inventory_AddItemQuantityToTypeGroup(inventory+0x1d4,item,1,types.entries[i]);}PartyRoster_RemoveCharacterBySlotIdAndCompact(inventory,(signed char)H(self,0x480));}
