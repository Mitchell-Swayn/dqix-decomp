#include <globaldefs.h>
ARM
extern "C" void func_ov000_0217f518(void *object, unsigned int mode);
extern "C" void func_ov000_0217636c(void *object, unsigned int mode);
// Original: arm9/ov000 @ 0x02170FD0; symbol: func_ov000_02170fd0; size: 0x2C.
extern "C" void InitializeObjectAndConfigureSelectionIfPresent(void *object, unsigned int mode) {
    func_ov000_0217f518(object, mode);
    if (*(void **)((unsigned char *)object + 0x38))
        func_ov000_0217636c(object, mode);
}
