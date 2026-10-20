#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" {
struct Character { unsigned char pad[0x150];unsigned char *state; };
struct Entry { unsigned a,b;unsigned kind:4;unsigned other:27;unsigned special:1; };
Character *GameState_GetObjectWithFlag100(GameState *,int);
Entry *ZoneState2754_FindPrimaryRecordByKey(void *,int);int Inventory_TestItemConsumableFlag(Entry *);
void CharacterState_RemoveCarriedItemAtIndex(void *,signed char);bool GameState_CopyStatisticsRecord(void *);void Statistics_AddFlaggedItemConsumptionCount(void *,int);void GameState_StoreStatisticsRecord(void *);
// Original: arm9/main @ 0x020DDCBC; symbol: func_020ddcbc; size: 0x110.
int ValidatePartyIndexAndResourceSlot(int index,int slot,void *resource) {
    bool valid;if(index>=0&&index<=3)valid=true;else valid=false;
    if(!valid)return 0;if(!resource)return 0;if(slot<0||slot>=8)return 0;
    Character *character=GameState_GetObjectWithFlag100(GameState::GetInstance(),index);if(!character)return 0;
    short *slots=(short *)(character->state+0x454);if(!slots)return 0;
    Entry *entry=ZoneState2754_FindPrimaryRecordByKey(resource,slots[slot]);if(!entry)return 0;if(!Inventory_TestItemConsumableFlag(entry))return 0;
    switch(entry->kind){case 8:case 9:case 10:CharacterState_RemoveCarriedItemAtIndex(character->state,(signed char)slot);break;}
    if(entry->special){unsigned work[44];GameState_CopyStatisticsRecord(work);Statistics_AddFlaggedItemConsumptionCount(work,1);GameState_StoreStatisticsRecord(work);}
    return 1;
}
}
