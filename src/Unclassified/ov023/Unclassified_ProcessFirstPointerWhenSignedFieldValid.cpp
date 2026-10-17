#include <globaldefs.h>
ARM
extern "C" void func_ov005_02155108(void *);
// Original: arm9/ov023 @ 0x021E3184; symbol: func_ov023_021e3184; size: 0x2C.
extern "C" void Unclassified_ProcessFirstPointerWhenSignedFieldValid(void *object) {
    signed char value = *(signed char *)((unsigned char *)object + 0x4E6);
    if (value != 0) {
        if (value != -1) {
            void *pointer = *(void **)object;
            if (pointer != 0)
                func_ov005_02155108(pointer);
        }
    }
}
