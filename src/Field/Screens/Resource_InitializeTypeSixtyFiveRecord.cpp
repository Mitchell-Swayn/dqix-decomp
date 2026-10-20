#include <globaldefs.h>
ARM
extern "C" void LinkedQueue_InitializeNodeStatus(signed char* p);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
// Original: arm9/ov017 @ 0x021A7D78; symbol: func_ov017_021a7d78; size: 0x60.
extern "C" void Resource_InitializeTypeSixtyFiveRecord(signed char* self) {
    LinkedQueue_InitializeNodeStatus(self);
    *(unsigned char*)self = 0x41;
    _ZN13SafeAllocator21ResetAllocatorPointerEv(self + 8);
    int zero = 0;
    int invalid = zero - 1;
    *(int*)(self + 0x1C) = zero;
    *(int*)(self + 0x20) = zero;
    *(int*)(self + 0x24) = zero;
    *(int*)(self + 0x28) = invalid;
    *(int*)(self + 0x2C) = zero;
    *(short*)(self + 0x30) = (short)invalid;
    *(int*)(self + 0x34) = invalid;
    *(short*)(self + 0x38) = (short)zero;
    *(short*)(self + 0x3A) = (short)zero;
    *(int*)(self + 0x3C) = zero;
    *(int*)(self + 0x40) = zero;
    *(int*)(self + 0x44) = zero;
    *(int*)(self + 0x48) = zero;
    *(int*)(self + 0x4C) = zero;
}
