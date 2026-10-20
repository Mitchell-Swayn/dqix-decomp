#include <globaldefs.h>
ARM
extern "C" unsigned char* Combat_GetPartyCharacterData(void*,int);
extern "C" int Grotto_ReadBossOverrideOrSevenBitObjectValue(void*,int);
// Original: arm9/ov000 @ 0x02159E60; symbol: func_ov000_02159e60; size: 0x4c.
// Reads the active vocation's party level, or the nonparty combatant level accessor.
extern "C" signed char Combat_GetCombatantLevel(void* battle,int slot) {
 int result;
 // Keep the common classification join: the compiler materializes this boolean.
 bool party;
 if(slot>=0) { if(slot<=3) {party=true;goto classified;} }
 party=false;
classified:
 if(party) {
  unsigned char* character=Combat_GetPartyCharacterData(battle,slot);
  result=*(unsigned short*)(character+0x16c+*(int*)(character+0x950)*2);
 } else result=Grotto_ReadBossOverrideOrSevenBitObjectValue(battle,slot);
 return result;
}
