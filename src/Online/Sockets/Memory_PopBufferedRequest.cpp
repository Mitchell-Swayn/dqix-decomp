#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" void Memory_ProcessBufferedRequest(unsigned size, unsigned unused);
// Original: arm9/ov031 @ 0x02205EBC; symbol: func_ov031_02205ebc; size: 0x3C.
extern "C" void* Memory_PopBufferedRequest(void* queue) {
    void* state = *(void**)((char*)queue + 0x64);
    int irq = _Z20DisableIRQInterruptsv();
    void* request = *(void**)((char*)state + 0xF8);
    if (request != 0) {
        *(void**)((char*)state + 0xF8) = 0;
        Memory_ProcessBufferedRequest((unsigned)request, 0);
    }
    _Z20SetIRQInterruptStatei(irq);
    return request;
}
