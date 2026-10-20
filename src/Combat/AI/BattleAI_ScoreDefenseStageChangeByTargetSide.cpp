#include <globaldefs.h>
ARM
extern "C" int BattleAI_SelectEnabledActionPolicyEntry(void*,int);
extern "C" void BattleAI_ScoreHostileAilmentAndDebuffTargets(void*,int);
extern "C" void BattleAI_ScorePartyStatusRemovalAndBuffTargets(void*,int);
// Original: arm9/ov024 @ 0x021FBDB4; symbol: DispatchEntryPairByLinkedMode; size: 0x88.
// Selects entry pair2/14 or3/6 based on linked mode bits8-9, then dispatches entry18.
extern "C" void BattleAI_ScoreDefenseStageChangeByTargetSide(char* p){
 unsigned flags=*(unsigned*)(*(char**)(p+0x64c)+8);
 if(((flags<<22)>>30)==1){
 if(!BattleAI_SelectEnabledActionPolicyEntry(p,2))return;if(!BattleAI_SelectEnabledActionPolicyEntry(p,14))return;BattleAI_ScoreHostileAilmentAndDebuffTargets(p,18);
 }else{if(!BattleAI_SelectEnabledActionPolicyEntry(p,3))return;if(!BattleAI_SelectEnabledActionPolicyEntry(p,6))return;BattleAI_ScorePartyStatusRemovalAndBuffTargets(p,18);}
}
