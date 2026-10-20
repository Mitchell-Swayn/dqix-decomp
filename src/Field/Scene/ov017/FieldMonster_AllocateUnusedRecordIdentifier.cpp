#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct E;
extern "C" void* PartySync_GetSharedRecordTable();
extern "C" E* PartySync_FindEntryByKey(E*,unsigned);
extern "C" unsigned short GameStateAllocateUnusedHighIdentifier_UnknownRoleInitializedBytes;
// Original: arm9/ov017 @ 0x021A1944; symbol: FieldMonster_AllocateUnusedRecordIdentifier; size: 0xDC.
// Allocates a key below 0x7ff8 unused by 48 field objects and the four-record table.
extern "C" unsigned short FieldMonster_AllocateUnusedRecordIdentifier() {
 GameState* state=GameState::GetInstance();
 E* table=(E*)PartySync_GetSharedRecordTable();
retry:
 if(GameStateAllocateUnusedHighIdentifier_UnknownRoleInitializedBytes>0x7ff7)GameStateAllocateUnusedHighIdentifier_UnknownRoleInitializedBytes=1;
 for(int row=0;row<4;++row) {
  for(int column=0;column<12;++column) {
   GameObject* object=state->GetMaybeFieldMonsterByIndex(row*12+0x70+column);
   if(object && GameStateAllocateUnusedHighIdentifier_UnknownRoleInitializedBytes==*(unsigned short*)((char*)object+0x16a)){
    ++GameStateAllocateUnusedHighIdentifier_UnknownRoleInitializedBytes;goto retry;
   }
  }
 }
 if(PartySync_FindEntryByKey(table,GameStateAllocateUnusedHighIdentifier_UnknownRoleInitializedBytes)) {++GameStateAllocateUnusedHighIdentifier_UnknownRoleInitializedBytes;goto retry;}
 return GameStateAllocateUnusedHighIdentifier_UnknownRoleInitializedBytes++;
}
