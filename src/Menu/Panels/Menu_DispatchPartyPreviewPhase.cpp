#include <globaldefs.h>
extern "C" void Menu_BeginRequestedPartyPreviewClose();
extern "C" void Menu_AdvancePartyPreviewInitialization(void *);
extern "C" void Graphics_AdvanceBrightnessTransitionAndUpdateOwner(void *);
extern "C" void AdvanceFadeOutAndResetOwnerPhase(void *);
// Original: arm9/ov023 @ 0x021E3030; symbol: func_ov023_021e3030; size: 0x54.
extern "C" void Menu_DispatchPartyPreviewPhase(void *owner) {
    Menu_BeginRequestedPartyPreviewClose();
    switch (*(signed char *)((char *)owner + 0x4e6)) {
    case 0: Menu_AdvancePartyPreviewInitialization(owner); break;
    case 3: Graphics_AdvanceBrightnessTransitionAndUpdateOwner(owner); break;
    case 1: AdvanceFadeOutAndResetOwnerPhase(owner); break;
    default: break;
    }
}
