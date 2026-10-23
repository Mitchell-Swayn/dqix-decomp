#include <globaldefs.h>
ARM
extern "C" unsigned short BattleAI_SelectActionByWeightProfile(void*,int,int,void*,int);
// Original: arm9/main @ 0x0208A4EC; symbol: func_0208a4ec; size: 0x20.
extern "C" unsigned short BattleAI_SelectActionWithThirdWeightProfile(void* owner,int index,void** out,int kind) {
    return BattleAI_SelectActionByWeightProfile(owner,2,index,out,kind);
}
