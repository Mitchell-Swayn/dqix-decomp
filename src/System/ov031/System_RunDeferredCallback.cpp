#include <globaldefs.h>
ARM
extern "C" void func_ov031_02240f74(void*);
extern "C" void System_RunCallbackAndAwaitContextCompletion(void);
extern "C" void func_ov031_0224030c(void);
extern "C" unsigned char data_ov031_02290fbc[];
// Original: arm9/ov031 @ 0x0223FDE4; symbol: func_ov031_0223fde4; size: 0x3C.
extern "C" void System_RunDeferredCallback(void (*callback)(void)) {
    func_ov031_02240f74((void*)callback);
    System_RunCallbackAndAwaitContextCompletion();
    unsigned char* state = data_ov031_02290fbc;
    ((void (*)(unsigned))*(void**)(state + 0x0c))(*(unsigned*)(state + 0x18));
    func_ov031_0224030c();
    *(unsigned*)data_ov031_02290fbc = 0;
    callback();
}
