#include <globaldefs.h>
ARM
extern "C" unsigned char data_02111304[];
// Original: arm9/ov031 @ 0x02203288; symbol: func_ov031_02203288; size: 0x1C.
extern "C" void StoreValueAtNestedGlobalOffset38IfPresent(unsigned int value) {
    void *first = *(void **)(data_02111304 + 4);
    void *object = *(void **)((char *)first + 0xa4);
    if (object)
        *(unsigned int *)((char *)object + 0x38) = value;
}
