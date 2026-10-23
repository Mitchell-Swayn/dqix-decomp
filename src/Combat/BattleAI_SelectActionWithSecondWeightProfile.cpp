#include <globaldefs.h>
ARM
extern "C" unsigned short BattleAI_SelectActionByWeightProfile(void*,int,int,void*,int);
// Original: arm9/main @ 0x0208A4CC; symbol: func_0208a4cc; size: 0x20.
extern "C" unsigned short BattleAI_SelectActionWithSecondWeightProfile(void* owner,int index,void** out,int kind) {
    return BattleAI_SelectActionByWeightProfile(owner,1,index,out,kind);
}
