#include <globaldefs.h>
ARM
extern "C" int BattleAI_SelectEnabledActionPolicyEntry(void*,int);
extern "C" void BattleAI_ScoreHostileAilmentAndDebuffTargets(void*,int);
extern "C" void BattleAI_ScorePartyStatusRemovalAndBuffTargets(void*,int);
// Original: arm9/ov024 @ 0x021FBE3C; symbol: Combat_DispatchEntryNineteenForDescriptorMode; size: 0x84.
// Uses descriptor mode bits 8-9 to gate entry 19 dispatch on entries 3 and 15 or 7.
extern "C" void Combat_DispatchEntryNineteenForDescriptorMode(char* self) {
 if(((*(unsigned*)(*(char**)(self+0x64c)+8)<<22)>>30)==1) {
 if(!BattleAI_SelectEnabledActionPolicyEntry(self,3))return;
 if(!BattleAI_SelectEnabledActionPolicyEntry(self,15))return;
 BattleAI_ScoreHostileAilmentAndDebuffTargets(self,19);
 }else{
 if(!BattleAI_SelectEnabledActionPolicyEntry(self,3))return;
 if(!BattleAI_SelectEnabledActionPolicyEntry(self,7))return;
 BattleAI_ScorePartyStatusRemovalAndBuffTargets(self,19);
 }
}
