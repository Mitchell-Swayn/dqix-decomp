#include <globaldefs.h>
ARM
extern "C" unsigned int _fmul(unsigned int, unsigned int);
struct PackedType { unsigned short pad : 7; unsigned short type : 4; unsigned short rest : 5; };
// Original: arm9/ov024 @ 0x021F6D80; symbol: func_ov024_021f6d80; size: 0x54.
extern "C" int Math_ScalePairByFiveQuartersForNestedType11(void *self) {
    void *nested = *(void **)((char *)self + 8);
    if (nested != 0 && (((PackedType *)((char *)nested + 0xA))->type == 0xB)) {
        *(unsigned int *)((char *)self + 0x1C) = _fmul(0x3FA00000, *(unsigned int *)((char *)self + 0x14));
        *(unsigned int *)((char *)self + 0x20) = _fmul(0x3FA00000, *(unsigned int *)((char *)self + 0x18));
    }
    return 1;
}
