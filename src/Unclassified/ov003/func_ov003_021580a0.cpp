#include <globaldefs.h>
ARM
extern "C" void Object_ClearPackedBitFieldsAndTwoWords(unsigned int *p);
extern "C" void *memset(void *, int, unsigned int);
// Original: arm9/ov003 @ 0x021580A0; symbol: func_ov003_021580a0; size: 0x38.
extern "C" void func_ov003_021580a0(void *obj) {
    Object_ClearPackedBitFieldsAndTwoWords((unsigned int *)obj);
    memset((char *)obj + 0x0c, 0, 0x38);
    memset((char *)obj + 0x44, 0, 0x200);
    *(void **)((char *)obj + 4) = (char *)obj + 0x44;
}
