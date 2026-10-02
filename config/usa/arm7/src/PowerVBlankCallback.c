/* Startup installs this VBlank callback; LED updates begin after power setup. */
#include "PowerState.h"

extern void ARM7_UpdatePowerLed(void);

void ARM7_PowerVBlankCallback(void)
{
    if (ARM7_PowerState.initialized) {
        ARM7_UpdatePowerLed();
    }
}
