#include <globaldefs.h>
ARM
extern "C" void* Combat_GetPartyCharacterData(int);
extern "C" bool CharacterState_HasLearnedSpells(void*);
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" bool CombatEffect_TargetHasFizzle(void*);
extern "C" bool Combatant_TestPrimaryStatusFlagBit9(void*);
// Original: arm9/ov024 @ 0x021ED9DC; symbol: Combat_TestPartyFlagsAndUnrestrictedDescriptor; size: 0x84.
// Requires active party flags and nonzero descriptor kind, excluding descriptor 100 and record 200 flags.
extern "C" bool Combat_TestPartyFlagsAndUnrestrictedDescriptor(int* self,int index) {
 void* party=Combat_GetPartyCharacterData(*self);if(!party)return false;
 if(!CharacterState_HasLearnedSpells(party))return false;
 char* combatant=_Z16GetCombatantByIDii(*self,index);if(!combatant)return false;
 if(!*(unsigned short*)(*(char**)(combatant+0x138)+2))return false;
 if(CombatEffect_TargetHasFizzle(combatant))return false;
 return !Combatant_TestPrimaryStatusFlagBit9(combatant);
}
