#include <globaldefs.h>
ARM
// Original: arm9/ov013 @ 0x02184338; symbol: func_ov013_02184338; size: 0x28.
extern "C" unsigned int ComputeIndexedEntryAddressAtStride40(void *object, unsigned int index) {
    unsigned int base = *(unsigned int *)((char *)object + 0x40);
    unsigned int result = 0;
    if (base) {
        unsigned int count = *(unsigned short *)((char *)object + 0x4e);
        if (index < count)
            result = base + index * 0x28;
    }
    return result;
}
