#include <globaldefs.h>
ARM
struct ModeBits {unsigned low:8;unsigned mode:2;unsigned high:22;};
extern "C" int BattleAI_SelectEnabledActionPolicyEntry(void*,int);
extern "C" void BattleAI_ScoreHostileAilmentAndDebuffTargets(void*,int);
extern "C" void BattleAI_ScorePartyStatusRemovalAndBuffTargets(void*,int);
// Original: arm9/ov024 @ 0x021FBD2C; symbol: DispatchModeDependentByteEntryPair; size: 0x88.
// Selects byte entries3/13 in mode1 or2/5 otherwise, then dispatches operation17.
extern "C" void BattleAI_ScoreAttackStageChangeByTargetSide(char* self) {
if(((ModeBits*)(*(char**)(self+0x64c)+8))->mode==1) {
if(!BattleAI_SelectEnabledActionPolicyEntry(self,3))return;if(!BattleAI_SelectEnabledActionPolicyEntry(self,13))return;BattleAI_ScoreHostileAilmentAndDebuffTargets(self,17);
}else {
if(!BattleAI_SelectEnabledActionPolicyEntry(self,2))return;if(!BattleAI_SelectEnabledActionPolicyEntry(self,5))return;BattleAI_ScorePartyStatusRemovalAndBuffTargets(self,17);
}
}
