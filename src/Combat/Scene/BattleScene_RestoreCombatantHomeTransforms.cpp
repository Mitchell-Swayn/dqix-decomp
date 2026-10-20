#include <globaldefs.h>
ARM
extern "C" {void* _ZN9GameState11GetInstanceEv();char* _ZN9GameState19GetCombatantByIndexEi(void*,int);unsigned PartySelection_GetMemberMask(void*,unsigned);void CombatantMotion_RestoreHomeTransform(void*);void CombatantMotion_DisableSidestep(char*);}
// Original: arm9/ov000 @ 0x02167E6C; symbol: ResetEligiblePartyAndReservedCombatants; size: 0xa4.
// Resets eligible party slots0-3 and reserved combatantsC0-C7, sets low state bits1.
extern "C" void BattleScene_RestoreCombatantHomeTransforms(unsigned char* self){void* state=_ZN9GameState11GetInstanceEv();for(int i=0;i<4;++i)if(PartySelection_GetMemberMask(*(void**)(self+0x2a0),(unsigned char)i)){char* obj=_ZN9GameState19GetCombatantByIndexEi(state,i);if(obj){CombatantMotion_RestoreHomeTransform(obj);CombatantMotion_DisableSidestep(obj);}}for(int i=192;i<200;++i){char* obj=_ZN9GameState19GetCombatantByIndexEi(state,i);if(obj){CombatantMotion_RestoreHomeTransform(obj);CombatantMotion_DisableSidestep(obj);}}self[0x5951]=(self[0x5951]&~3)|1;}
