#include <globaldefs.h>
ARM
extern "C" void ModsNitroStream_FreeStorage(void);
// Original: arm9/ov016 @ 0x0218E62C; symbol: func_ov016_0218e62c; size: 0x14.
extern "C" void *ModsNitroStream_Delete(void *value) {
    ModsNitroStream_FreeStorage();
    return value;
}
