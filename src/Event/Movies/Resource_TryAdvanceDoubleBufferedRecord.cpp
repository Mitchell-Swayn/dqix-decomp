#include <globaldefs.h>
ARM
extern "C" int Resource_AdvanceDoubleBufferedRecord(void *state);

// Original: arm9/ov016 @ 0x0218E6C0; symbol: func_ov016_0218e6c0; size: 0x24.
extern "C" int Resource_TryAdvanceDoubleBufferedRecord(void *state) {
    if (state == 0)
        return 0;
    return Resource_AdvanceDoubleBufferedRecord(state) == 1;
}
