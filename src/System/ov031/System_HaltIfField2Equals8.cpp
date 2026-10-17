#include <globaldefs.h>
ARM
extern "C" void SetStateWithTransitionCallbacks(int value);
extern "C" void DisableInterruptsAndHaltForever(void);
// Original: arm9/ov031 @ 0x0223A040; symbol: func_ov031_0223a040; size: 0x20.
extern "C" void System_HaltIfField2Equals8(void *object) {
    if (*(unsigned short *)((char *)object + 2) == 8) {
        SetStateWithTransitionCallbacks(9);
        DisableInterruptsAndHaltForever();
    }
}
