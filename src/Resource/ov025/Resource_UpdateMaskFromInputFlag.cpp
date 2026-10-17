#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance();
extern "C" void Object_SetUnsignedIntAtOffset4(int self, unsigned int mask);
extern "C" void ClearWordAtOffset4MaskedBits(int self, unsigned int mask);
// Original: arm9/ov025 @ 0x021E8314; symbol: func_ov025_021e8314; size: 0x30.
extern "C" int Resource_UpdateMaskFromInputFlag(unsigned char *input) {
    void *resources = GameResources_GetInstance();
    if (input[8]) ClearWordAtOffset4MaskedBits((int)resources, 0x400);
    else Object_SetUnsignedIntAtOffset4((int)resources, 0x400);
    return 1;
}
