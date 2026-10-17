#include <globaldefs.h>
ARM

extern "C" void *data_ov031_02290dc8[3];
extern "C" void (*data_ov031_02290dc0)(void *);

// Original: arm9/ov031 @ 0x0223E348; symbol: func_ov031_0223e348; size: 0x44.
extern "C" void Unclassified_InvokeAndClearPendingCallbacks(void) {
    int i = 0;
    do {
        void *pending = data_ov031_02290dc8[i];
        if (pending != 0) {
            data_ov031_02290dc0(pending);
            data_ov031_02290dc8[i] = 0;
        }
    } while (++i < 3);
}
