#include <globaldefs.h>
ARM
extern "C" void* data_ov031_0224e5e8;
extern "C" unsigned char data_ov031_02249ba8[];
extern "C" void Memory_ReleaseContextBuffersAndReset(void);
typedef void (*DispatchCallback)(void*, void*, unsigned);
// Original: arm9/ov031 @ 0x02216A2C; symbol: func_ov031_02216a2c; size: 0x58.
extern "C" void DispatchPendingOverlayCallback(void) {
    void* object = (void*)*(volatile void**)((char*)&data_ov031_0224e5e8 + 8);
    if (!object)
        return;
    unsigned char* state = (unsigned char*)object + 0x1000;
    DispatchCallback callback = *(DispatchCallback*)(state + 0x210);
    if (*(void**)(state + 0x314))
        Memory_ReleaseContextBuffersAndReset();
    callback(data_ov031_02249ba8, (void*)*(volatile void**)((char*)&data_ov031_0224e5e8 + 8), 0);
    *(volatile void**)((char*)&data_ov031_0224e5e8 + 8) = 0;
}
