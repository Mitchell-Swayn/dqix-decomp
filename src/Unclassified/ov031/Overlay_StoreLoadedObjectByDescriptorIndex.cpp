#include <globaldefs.h>
ARM
extern "C" unsigned Network_FindEnabledAddressValue(unsigned value);
extern "C" unsigned func_ov031_02239250(void);
extern "C" unsigned char *data_ov031_02290d20;
// Original: arm9/ov031 @ 0x0223B040; symbol: func_ov031_0223b040; size: 0x3C.
extern "C" int Overlay_StoreLoadedObjectByDescriptorIndex(void *descriptor) {
    unsigned index = Network_FindEnabledAddressValue((unsigned)((char *)descriptor + 0x0a));
    if (!index) return 0;
    unsigned resource = func_ov031_02239250();
    *(unsigned *)(data_ov031_02290d20 + 0xaa0 + (index - 1) * 4) = resource;
    return 1;
}
