#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" {
struct Character { unsigned char pad[0x150];unsigned char *state; };
struct Entry { unsigned a,b;unsigned kind:4;unsigned other:27;unsigned special:1; };
Character *GameState_GetObjectWithFlag100(GameState *,int);
Entry *FindSerializedPrimaryRecordByKey(void *,int);int IsBitFieldFlagNonzero(Entry *);
void RemoveHalfwordArrayElementAndShiftRemainingEightSlots(void *,signed char);bool GameState_CopyB0ByteStateBufferToOutput(void *);void AddToBitFieldAtOffset18SaturatingAt100(void *,int);void GameState_Copy176BytesAtOffset7540(void *);
// Original: arm9/main @ 0x020DDCBC; symbol: func_020ddcbc; size: 0x110.
int ValidatePartyIndexAndResourceSlot(int index,int slot,void *resource) {
    bool valid;if(index>=0&&index<=3)valid=true;else valid=false;
    if(!valid)return 0;if(!resource)return 0;if(slot<0||slot>=8)return 0;
    Character *character=GameState_GetObjectWithFlag100(GameState::GetInstance(),index);if(!character)return 0;
    short *slots=(short *)(character->state+0x454);if(!slots)return 0;
    Entry *entry=FindSerializedPrimaryRecordByKey(resource,slots[slot]);if(!entry)return 0;if(!IsBitFieldFlagNonzero(entry))return 0;
    switch(entry->kind){case 8:case 9:case 10:RemoveHalfwordArrayElementAndShiftRemainingEightSlots(character->state,(signed char)slot);break;}
    if(entry->special){unsigned work[44];GameState_CopyB0ByteStateBufferToOutput(work);AddToBitFieldAtOffset18SaturatingAt100(work,1);GameState_Copy176BytesAtOffset7540(work);}
    return 1;
}
}
