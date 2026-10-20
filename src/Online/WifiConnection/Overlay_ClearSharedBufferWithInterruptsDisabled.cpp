#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" unsigned Network_GetWirelessWorkspace();
extern "C" void VectorizedMemset(void*, int, unsigned);
// Original: arm9/ov031 @ 0x0220EADC; symbol: func_ov031_0220eadc; size: 0x54.
extern "C" void Overlay_ClearSharedBufferWithInterruptsDisabled(void) {
    int irqState = _Z20DisableIRQInterruptsv();
    unsigned shared = Network_GetWirelessWorkspace();
    if (shared == 0) {
        _Z20SetIRQInterruptStatei(irqState);
        return;
    }
    char* object = (char*)(shared + 0x2000);
    void* buffer = *(void**)(object + 0x270);
    if (buffer != 0) {
        int length = *(int*)(object + 0x274);
        if (length > 0) VectorizedMemset(buffer, 0, length);
    }
    _Z20SetIRQInterruptStatei(irqState);
}
