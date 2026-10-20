#include <globaldefs.h>
ARM
struct Object;
extern "C" void Graphics_UpdateBoundedSixteenByteEntry(Object *p, unsigned int index, unsigned int a, unsigned int b, unsigned short value);
// Original: arm9/ov023 @ 0x021F7C68; symbol: func_ov023_021f7c68; size: 0x38.
extern "C" void Graphics_SetBoundedEntryAndUpdate(unsigned char *object, unsigned char a, unsigned char b, unsigned char c) {
    object[0x4C] = a;
    object[0x4D] = b;
    object[0x4E] = c;
    *(unsigned int *)(object + 0x48) = 1;
    Graphics_UpdateBoundedSixteenByteEntry((Object *)(object + 0x28), object[0x4C], object[0x4D], object[0x4E], 0xFFFF);
}
