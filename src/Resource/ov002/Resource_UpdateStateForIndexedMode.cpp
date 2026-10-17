#include <globaldefs.h>
ARM

extern "C" void func_ov016_0218b5c0(unsigned, int);
extern "C" void SetLoadedResourceIndexMask(int);

// Original: arm9/ov002 @ 0x0216C28C; symbol: func_ov002_0216c28c; size: 0x4C.
extern "C" void Resource_UpdateStateForIndexedMode(void *object, unsigned value) {
    unsigned char *base = (unsigned char *)object;
    unsigned mode = value & 0xFF;
    base[0x1C7B] = (unsigned char)value;
    if (mode != 0xB && mode != 0xC) {
        return;
    }
    func_ov016_0218b5c0(1, *(signed char *)(base + 0x1C20));
    func_ov016_0218b5c0(1, *(signed char *)(base + 0x1C21));
    SetLoadedResourceIndexMask(-1);
}
