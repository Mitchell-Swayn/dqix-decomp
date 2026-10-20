#include <globaldefs.h>

// Original: arm9/ov003 @ 0x0215873C; symbol: func_ov003_0215873c; size: 0x18.
extern "C" ARM void Alltrades_ResetTransformationEffectLoading(void* object) {
    *(int*)((char*)object + 0x20c) = -1;
    *(int*)((char*)object + 0x32c) = 0;
    *((unsigned char*)object + 0x208) = 0;
}
