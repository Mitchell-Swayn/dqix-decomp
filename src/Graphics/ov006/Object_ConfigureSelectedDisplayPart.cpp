#include <globaldefs.h>
ARM
extern "C" void WriteResolvedEntryHalfword0E(char *, int, short);
extern "C" void Object_SetSelectedPartLowTwoBitMode(char *, int, int);
extern "C" void WriteResolvedEntryByte15Flag2(unsigned char *, int, int);
extern "C" int Object_CreateAndConfigureSelectedDisplayPart(char *, int);
extern "C" void Object_SetGroupNibbleAndTextureLowFourBits(char *, int, unsigned char);
extern "C" void ClearResolvedEntryByteC5Bit20(unsigned char *, int);

// Original: arm9/ov006 @ 0x0215FCF0; symbol: func_ov006_0215fcf0; size: 0x70.
extern "C" void Object_ConfigureSelectedDisplayPart(void *object) {
    unsigned char value = *((unsigned char *)object + 0x386);
    char *part = *(char **)((unsigned char *)object + 0x14);
    WriteResolvedEntryHalfword0E(part, 0x5a, (short)(value + 0x29));
    Object_SetSelectedPartLowTwoBitMode(part, 0x5a, 1);
    WriteResolvedEntryByte15Flag2((unsigned char *)part, 0xf, 1);
    Object_CreateAndConfigureSelectedDisplayPart(part, 0xf);
    Object_SetGroupNibbleAndTextureLowFourBits(part, 0xf, 2);
    ClearResolvedEntryByteC5Bit20((unsigned char *)part, 0xf);
}
