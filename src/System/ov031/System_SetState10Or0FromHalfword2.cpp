#include <globaldefs.h>
ARM
extern "C" void SetStateWithTransitionCallbacks(int value);
// Original: arm9/ov031 @ 0x02239B98; symbol: func_ov031_02239b98; size: 0x28.
extern "C" void System_SetState10Or0FromHalfword2(void *object) {
    if (*(unsigned short *)((char *)object + 2))
        SetStateWithTransitionCallbacks(10);
    else
        SetStateWithTransitionCallbacks(0);
}
