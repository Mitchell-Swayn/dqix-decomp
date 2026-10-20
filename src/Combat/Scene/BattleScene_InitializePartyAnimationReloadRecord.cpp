#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02168268; symbol: func_ov000_02168268; size: 0x1C.
extern "C" void BattleScene_InitializePartyAnimationReloadRecord(void *object) {
    *(signed char *)object = -1;
    *((char *)object + 1) = 0;
    *(short *)((char *)object + 2) = -1;
    *(short *)((char *)object + 4) = -1;
}
