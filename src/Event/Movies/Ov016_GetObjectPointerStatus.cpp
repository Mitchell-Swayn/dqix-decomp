#include <globaldefs.h>
ARM
extern "C" unsigned int Ov016_SelectStatusFromObjectPointers(void *object);
// Original: arm9/ov016 @ 0x0218E6A8; symbol: func_ov016_0218e6a8; size: 0x18.
extern "C" unsigned int Ov016_GetObjectPointerStatus(void *object) {
    return object ? Ov016_SelectStatusFromObjectPointers(object) : 0;
}
