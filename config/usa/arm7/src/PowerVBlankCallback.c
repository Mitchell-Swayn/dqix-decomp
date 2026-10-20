/* Startup installs this VBlank callback; LED updates begin after power setup. */
#include "PowerState.h"

extern void ARM7_UpdatePowerLed(void);

// Original: arm7/wram @ 0x037F84F0; symbol: ARM7_PowerVBlankCallback.
void ARM7_PowerVBlankCallback(void)
{
    if (ARM7_PowerState.initialized) {
        ARM7_UpdatePowerLed();
    }
}
