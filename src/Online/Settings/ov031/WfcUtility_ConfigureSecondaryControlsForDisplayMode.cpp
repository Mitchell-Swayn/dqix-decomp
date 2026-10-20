#include <globaldefs.h>
ARM
extern "C" void WfcUtility_GetNavigationContext(unsigned int*, unsigned int*);
extern "C" void WfcUtility_CreateAnimatedHeaderSprites(unsigned);
extern "C" void WfcUtility_ConfigureAlternatingModeSprites(unsigned);
// Original: arm9/ov031 @ 0x02223518; symbol: WfcUtility_ConfigureSecondaryControlsForDisplayMode; size: 0x50.
// Selects five-sprite creation or alternating-sprite configuration from the global display mode.
extern "C" void WfcUtility_ConfigureSecondaryControlsForDisplayMode(unsigned index)
{
    unsigned mode;
    WfcUtility_GetNavigationContext(&mode, 0);
    if(mode == 1) { WfcUtility_CreateAnimatedHeaderSprites(index); return; }
    if(mode != 2) return;
    WfcUtility_ConfigureAlternatingModeSprites(index);
}
