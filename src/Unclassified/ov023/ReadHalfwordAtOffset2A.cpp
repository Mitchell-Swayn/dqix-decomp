#include <globaldefs.h>

// ReadHalfwordAtOffset2A; field semantics beyond the observed offsets and masks remain unknown.
// Original: arm9/ov023 @ 0x021F9BC0; symbol: func_ov023_021f9bc0; size: 0x8.
extern "C" unsigned short ReadHalfwordAtOffset2A(const void *object)
{
    return *(const unsigned short *)((const unsigned char *)object + 0x2a);
}
