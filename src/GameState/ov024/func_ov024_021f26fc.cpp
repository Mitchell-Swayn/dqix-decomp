#include <globaldefs.h>
ARM
extern "C" void *FindIndexedGameStateObjectWithFlag400(void *, int);
extern "C" int HasNestedFlagBit3(const void *);
// Original: arm9/ov024 @ 0x021F26FC; symbol: func_ov024_021f26fc; size: 0x40.
extern "C" int func_ov024_021f26fc(void **self, unsigned short value, int unused, int *status, unsigned short *outValue) {
    void *object = FindIndexedGameStateObjectWithFlag400(*self, value);
    if (object == 0) return 0;
    if (HasNestedFlagBit3(object)) return 0;
    *outValue = value;
    *status = 1;
    return 1;
}
