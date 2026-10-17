#include <globaldefs.h>
ARM

extern "C" void (*data_ov031_0224c9c0)(void *);

// Original: arm9/ov031 @ 0x0220AA30; symbol: func_ov031_0220aa30; size: 0x38.
extern "C" void Unclassified_ResetAndInvokeStateCallback(void *object) {
    char *state = (char *)*(void **)((char *)object + 0xc);
    state[0x455] = 0;
    void *argument = *(void **)(state + 0x824);
    if (argument != 0) {
        data_ov031_0224c9c0(argument);
    }
    *(void **)(state + 0x824) = 0;
}
