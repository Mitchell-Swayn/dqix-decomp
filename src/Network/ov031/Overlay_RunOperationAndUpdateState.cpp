#include <globaldefs.h>
ARM
extern "C" void *data_ov031_02290d18[2];
extern "C" void DisableInterruptsAndHaltForever(void);
extern "C" void SetStateWithTransitionCallbacks(int);
extern "C" int SubmitOperationTwoAndNormalizePendingResult(unsigned);
extern "C" void System_SetState10Or0FromHalfword2(void);
// Original: arm9/ov031 @ 0x0223A47C; symbol: func_ov031_0223a47c; size: 0x50.
extern "C" int Overlay_RunOperationAndUpdateState(void) {
    if (*(unsigned int *)((char *)data_ov031_02290d18[1] + 0x40) != 1)
        DisableInterruptsAndHaltForever();
    SetStateWithTransitionCallbacks(3);
    if (SubmitOperationTwoAndNormalizePendingResult((unsigned)System_SetState10Or0FromHalfword2) == 2) return 1;
    SetStateWithTransitionCallbacks(9);
    return 0;
}
