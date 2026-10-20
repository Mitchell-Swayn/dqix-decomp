#include <globaldefs.h>
ARM
extern "C" void Resource_DestroyObjectAllocatorAndClearFlags(void *);

// Original: arm9/ov017 @ 0x021BEFCC; symbol: func_ov017_021befcc; size: 0x18.
extern "C" int Resource_DestroyAndMarkObjectActive(void *object) {
    Resource_DestroyObjectAllocatorAndClearFlags(object);
    ((unsigned char *)object)[1] = 1;
    return 1;
}
