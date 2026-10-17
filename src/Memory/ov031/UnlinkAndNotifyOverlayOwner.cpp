#include <globaldefs.h>
ARM
extern "C" void *data_ov031_02290d64;
extern "C" void UnlinkPointerPair(void *);
extern "C" void func_ov031_0223bf48(void *, void *);
// Original: arm9/ov031 @ 0x0223DCF4; symbol: func_ov031_0223dcf4; size: 0x40.
extern "C" void UnlinkAndNotifyOverlayOwner(void *pointer) {
    int segment = 0;
    UnlinkPointerPair(pointer);
    unsigned char *base = (unsigned char *)data_ov031_02290d64;
    if ((unsigned char *)pointer >= base + 0x1a0) segment = 1;
    unsigned char *table = base + segment * 0x1a0;
    void *callbackData = *(void **)(table + 0x19c);
    func_ov031_0223bf48(callbackData, pointer);
}
