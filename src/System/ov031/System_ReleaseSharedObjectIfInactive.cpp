#include <globaldefs.h>
ARM

extern "C" void func_ov031_0221e894(void *);
extern "C" void func_ov031_02236364(void *);
extern "C" void FreeSharedAllocationAndClearFlagWithInterruptMask(void **);
extern "C" unsigned char data_ov031_02250c04[];
extern "C" void *data_ov031_02250c08[];

// Original: arm9/ov031 @ 0x02226F18; symbol: func_ov031_02226f18; size: 0x50.
extern "C" void System_ReleaseSharedObjectIfInactive(void *context) {
    func_ov031_0221e894(context);
    if (context != 0) {
        void *object = *(void **)(data_ov031_02250c04 + 4);
        if (*((unsigned char *)object + 0x116) == 0 && data_ov031_02250c04[0] == 1) {
            func_ov031_02236364((char *)object + 0x117);
        }
    }
    FreeSharedAllocationAndClearFlagWithInterruptMask(data_ov031_02250c08);
}
