#include <globaldefs.h>
ARM
struct GameResources;
extern "C" GameResources *GameResources_GetInstance(void);
extern "C" void ClearWordAtOffset4MaskedBits(int self, unsigned int mask);
extern "C" void Object_SetUnsignedIntAtOffset4(int self, unsigned int value);
// Original: arm9/ov025 @ 0x021E7FDC; symbol: func_ov025_021e7fdc; size: 0x2C.
extern "C" int Resource_UpdateFlagFromObjectByte8(void *object) {
    unsigned char enabled = *((unsigned char *)object + 8);
    int resources = (int)GameResources_GetInstance();
    if (enabled)
        ClearWordAtOffset4MaskedBits(resources, 0x100000);
    else
        Object_SetUnsignedIntAtOffset4(resources, 0x100000);
    return 1;
}
