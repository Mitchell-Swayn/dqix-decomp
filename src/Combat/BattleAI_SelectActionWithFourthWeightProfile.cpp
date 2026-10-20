#include <globaldefs.h>
ARM
extern "C" unsigned short BattleAI_SelectActionByWeightProfile(void*,int,int,void**,int);
// Original: arm9/main @ 0x0208A50C; symbol: func_0208a50c; size: 0x20.
extern "C" unsigned short BattleAI_SelectActionWithFourthWeightProfile(void* owner,int index,void** out,int kind) {
    return BattleAI_SelectActionByWeightProfile(owner,3,index,out,kind);
}
