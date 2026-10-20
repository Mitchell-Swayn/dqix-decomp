#include <globaldefs.h>

// ReadHalfwordAtOffset6; field semantics beyond the observed offsets and masks remain unknown.
// Original: arm9/ov023 @ 0x021F6F08; symbol: func_ov023_021f6f08; size: 0x8.
extern "C" unsigned short MenuRecord_GetKey(const void *object)
{
    return *(const unsigned short *)((const unsigned char *)object + 6);
}
