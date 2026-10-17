#include <globaldefs.h>
extern "C" void func_ov023_021e4e3c();
extern "C" void func_ov023_021e33b4(void *);
extern "C" void func_ov023_021e3db0(void *);
extern "C" void AdvanceFadeOutAndResetOwnerPhase(void *);
// Original: arm9/ov023 @ 0x021E3030; symbol: func_ov023_021e3030; size: 0x54.
extern "C" void OV023_DispatchOwnerPhase(void *owner) {
    func_ov023_021e4e3c();
    switch (*(signed char *)((char *)owner + 0x4e6)) {
    case 0: func_ov023_021e33b4(owner); break;
    case 3: func_ov023_021e3db0(owner); break;
    case 1: AdvanceFadeOutAndResetOwnerPhase(owner); break;
    default: break;
    }
}
