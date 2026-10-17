#include <globaldefs.h>

// Original: arm9/ov003 @ 0x02156034; symbol: func_ov003_02156034; size: 0x20.
extern "C" ARM void* GetEntryFromBiasedSignedIndex1E4(void* object) {
    short index = (short)(*(signed short*)((char*)object + 0x1e4) - 0x13);
    return ((void**) *(void**)((char*)object + 0x20))[index];
}
