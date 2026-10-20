#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" char *BattleMenu_FindPartyCommandRecord(char *,int);
struct NestedFlags { unsigned char padding[0x22];unsigned short value:2;unsigned short remaining:14; };
// Original: arm9/ov000 @ 0x021760D4; symbol: func_ov000_021760d4; size: 0x60.
// Copies the low two bits of each combatant's nested halfword at +0x22 to its record byte +0x2F.
extern "C" void Combat_CopyLowTwoBitFieldToFourRecords(char *self) {
 GameState *state=GameState::GetInstance();
 for(int index=0;index<4;index++) {
 char *record=BattleMenu_FindPartyCommandRecord(self,index);
 if(!record)continue;
 GameObject *combatant=state->GetCombatantByIndex(index);
 if(combatant)record[0x2f]=(*(NestedFlags **)((char *)combatant+0x138))->value;
 }
}
