#include <globaldefs.h>
ARM
extern "C" void Graphics_ResetCountedTransferEntriesWithModeZero(void *);
// Original: arm9/ov003 @ 0x0216757C; symbol: func_ov003_0216757c; size: 0x20.
extern "C" void ResetCountedTransferEntriesIfEnabledAndPresent(void *object) {
    if (*(unsigned char *)((char *)object + 0x74)) {
        void *state = *(void **)((char *)object + 0x10);
        if (state)
            Graphics_ResetCountedTransferEntriesWithModeZero(state);
    }
}
