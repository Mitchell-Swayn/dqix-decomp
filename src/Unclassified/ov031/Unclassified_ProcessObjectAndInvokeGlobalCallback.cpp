#include <globaldefs.h>
ARM
extern "C" void Unclassified_InvokeGlobalCallbackOnObjectField30(void *);
extern "C" void func_ov031_0223faa8(void);
extern "C" unsigned char data_ov031_02290dc0[];
// Original: arm9/ov031 @ 0x0223EDB4; symbol: func_ov031_0223edb4; size: 0x2C.
extern "C" void Unclassified_ProcessObjectAndInvokeGlobalCallback(void *state, void *object) {
    Unclassified_InvokeGlobalCallbackOnObjectField30(object);
    func_ov031_0223faa8();
    ((void (*)(void *))(*(void **)data_ov031_02290dc0))(state);
}
