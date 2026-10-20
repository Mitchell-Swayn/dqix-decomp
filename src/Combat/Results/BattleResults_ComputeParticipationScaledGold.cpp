#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
// Original: arm9/ov023 @ 0x021F44D0; symbol: func_ov023_021f44d0; size: 0x7C.
extern "C" int BattleResults_ComputeParticipationScaledGold(char* p) {
 _ZN9GameState11GetInstanceEv();
 float base=(float)*(unsigned*)(p+0x58c4);
 float denominator=(float)*(unsigned short*)(p+0x58cc);
 float numerator=(float)*(unsigned short*)(p+0x58ce);
 float result=base*(numerator/denominator);
 if(0.0f<result && result<1.0f) result=1.0f;
 return (int)result;
}
