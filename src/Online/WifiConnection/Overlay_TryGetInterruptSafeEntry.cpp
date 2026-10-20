#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" unsigned Network_GetWirelessWorkspace();
extern "C" void* FindOverlayLinkedEntryByKey(void*);
// Original: arm9/ov031 @ 0x0220EC04; symbol: func_ov031_0220ec04; size: 0x58.
extern "C" void* Overlay_TryGetInterruptSafeEntry(void* object) {
    int irqState = _Z20DisableIRQInterruptsv();
    if (!Network_GetWirelessWorkspace()) {
        _Z20SetIRQInterruptStatei(irqState);
        return 0;
    }
    void* entry = FindOverlayLinkedEntryByKey(object);
    if (!entry) {
        _Z20SetIRQInterruptStatei(irqState);
        return 0;
    }
    _Z20SetIRQInterruptStatei(irqState);
    return (char*)entry + 0x10;
}
