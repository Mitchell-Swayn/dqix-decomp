#include <globaldefs.h>
ARM

// Original: arm9/ov016 @ 0x0218F508; symbol: func_ov016_0218f508; size: 0x38.
extern "C" int ModsNitroStream_Initialize(void *output, void *object) {
    *(void **)((char *)output + 0x0C) = object;
    *(int *)((char *)output + 4) = *(int *)((char *)object + 0x28) - *(int *)((char *)object + 0x24);
    void *storedObject = (void *)*(volatile void **)((char *)output + 0x0C);
    *(int *)((char *)output + 8) = *(int *)((char *)storedObject + 0x2C) - *(int *)((char *)storedObject + 0x24);
    *((unsigned char *)output + 0x10) = 0;
    return 1;
}
