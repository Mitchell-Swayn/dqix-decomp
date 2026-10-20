#include <globaldefs.h>
#include <GameState/GameState.h>
#pragma always_inline on
struct Slots{signed char entries[9];};
// Original data: arm9/main @ 0x20e87b4; symbol: data_020e87b4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000105060708090aff000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const Slots RecordUnseenPartySlotIdsAndCountChanges_UnknownRoleInitializedBytes;
extern "C" char *GameObject_GetLinkedIndexedState(GameObject*);
extern "C" int BitArray_ReadNonnegativeIndexMask(void*,void*,unsigned);
extern "C" void BitArray_SetIndexedBoolean(void*,void*,unsigned,int);
extern "C" bool GameState_CopyStatisticsRecord(void*);
extern "C" int GameState_StoreStatisticsRecord(const void*);
extern "C" void Statistics_AddNewEquipmentTypeCount(void*,unsigned);
struct TypeBits{unsigned kind:4;unsigned rest:28;};struct IdBits{unsigned low:12;unsigned id:11;unsigned rest:9;};
inline bool normalKind(char *entry){return ((TypeBits*)(entry+8))->kind<=7;}
// Original: arm9/main @ 0x0206E424; symbol: func_0206e424; size: 0x134.
extern "C" void RecordUnseenPartySlotIdsAndCountChanges(char *state,int index){bool valid;if(index>=0&&index<=3)valid=true;else valid=false;if(valid){GameObject *party=GameState::GetInstance()->GetPartyMemberByIndex(index);if(party){char *object=GameObject_GetLinkedIndexedState(party);if(object){Slots slots=RecordUnseenPartySlotIdsAndCountChanges_UnknownRoleInitializedBytes;unsigned char changes=0;for(unsigned char i=0;slots.entries[i]>=0;i++){char *entry=object+0x194+slots.entries[i]*32;bool normal=normalKind(entry);if(normal){unsigned short id=((IdBits*)(entry+12))->id;if(id&&!BitArray_ReadNonnegativeIndexMask(state,state+0x8c,id+0xc76)){BitArray_SetIndexedBoolean(state,state+0x8c,id+0xc76,1);++changes;}}}unsigned work[44];GameState_CopyStatisticsRecord(work);Statistics_AddNewEquipmentTypeCount(work,changes);GameState_StoreStatisticsRecord(work);}}}}
