#include <globaldefs.h>
ARM
#pragma always_inline on
extern "C" {void* _ZN9GameState11GetInstanceEv();void* GameState_GetObjectWithFlag100(void*,int);int GameObject_HasBattleMotionExclusionFlag80(char*);bool GameObject_IsBattleIdleMotionSuppressed(unsigned char*);unsigned GameObject_GetBattleGridIndexOrInvalid(unsigned char*);int CombatantMotion_GetActiveStatus(char*);}
inline int IsPartyIndex(int index){int result=0;if(index>=0)result=index<=3;return result;}
// Original: arm9/ov025 @ 0x021E1F40; symbol: func_ov025_021e1f40; size: 0xB4.
extern "C" int TestDifferentIndexAndComponentFlagsClear(unsigned char* p,int index){
if(!CombatantMotion_GetActiveStatus((char*)p))return 0;
if(index==*(short*)(p+4))return 0;
if(GameObject_HasBattleMotionExclusionFlag80((char*)p))return 0;
if(GameObject_GetBattleGridIndexOrInvalid(p)==255)return 0;
if(GameObject_IsBattleIdleMotionSuppressed(p))return 0;
if(IsPartyIndex(*(short*)(p+4))){void* game=_ZN9GameState11GetInstanceEv();char* object=(char*)GameState_GetObjectWithFlag100(game,*(short*)(p+4));if(object&&(*(unsigned*)(object+0x18c)&1))return 0;}
return 1;
}
