#include <globaldefs.h>
ARM
extern "C" void *Zone3D_GetMainInstance(void);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021EA9B0; symbol: Grotto_SetNestedWordFromGlobalObjectBit4; size: 0x2C.
// Reads bit 4 of the byte at global-object path +8 then +0xC, writes it to the nested output word, and returns one.
extern "C" int Grotto_SetNestedWordFromGlobalObjectBit4(void *p) {
    unsigned char *base = (unsigned char *)Zone3D_GetMainInstance();
    unsigned char *record = *(unsigned char **)(base + 8);
    int value = ((unsigned int)record[0xc] << 27) >> 31;
    Script_WriteIntegerReferenceOutput(p, value);
    return 1;
}
