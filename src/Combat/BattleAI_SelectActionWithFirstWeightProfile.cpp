#include <globaldefs.h>
ARM
extern "C" unsigned short BattleAI_SelectActionByWeightProfile(void*,int,int,void*,int);
// Original: arm9/main @ 0x0208A4AC; symbol: func_0208a4ac; size: 0x20.
extern "C" unsigned short BattleAI_SelectActionWithFirstWeightProfile(void* owner,int index,void** out,int kind) {
    return BattleAI_SelectActionByWeightProfile(owner,0,index,out,kind);
}
