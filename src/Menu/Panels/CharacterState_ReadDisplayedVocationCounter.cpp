#include <globaldefs.h>
// Original: arm9/ov023 @ 0x021E4250; symbol: func_ov023_021e4250; size: 0x14.
extern "C" unsigned int CharacterState_ReadDisplayedVocationCounter(void *object) {
    char *base = *(char **)((char *)object + 0x150);
    unsigned int offset = *(unsigned int *)(base + 0x950);
    char *entry = &base[offset];
    return (unsigned char)entry[0x186];
}
