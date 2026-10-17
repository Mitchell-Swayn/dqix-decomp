#include <globaldefs.h>
ARM
extern "C" int TestFlagBitOneAndModeOne(void*);
extern "C" int TestFlag2AndModeTwo(void*);
extern "C" int TestLinkedDescriptorFlag8(void*);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
// Original: arm9/ov024 @ 0x021F6CC0; symbol: func_ov024_021f6cc0; size: 0x64.
extern "C" int Object_ScalePairByThreeHalvesWhenFlagPredicateMatches(unsigned char* self) {
    unsigned char* object = *(unsigned char**)(self + 4);
    if (TestFlagBitOneAndModeOne(*(void**)(object + 0x138)) ||
        TestFlag2AndModeTwo(*(void**)(object + 0x138)) ||
        TestLinkedDescriptorFlag8(object)) {
        *(unsigned*)(self + 0x1c) = _fmul(0x3fc00000, *(unsigned*)(self + 0x14));
        *(unsigned*)(self + 0x20) = _fmul(0x3fc00000, *(unsigned*)(self + 0x18));
    }
    return 1;
}
