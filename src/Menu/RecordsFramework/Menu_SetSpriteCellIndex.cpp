#include <globaldefs.h>

// WriteHalfwordAtOffset22; field semantics beyond the observed offsets and masks remain unknown.
// Original: arm9/ov023 @ 0x021FB27C; symbol: func_ov023_021fb27c; size: 0x8.
extern "C" void Menu_SetSpriteCellIndex(void *object, unsigned short value)
{
    *(unsigned short *)((unsigned char *)object + 0x22) = value;
}
