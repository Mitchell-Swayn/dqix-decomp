/* Initialize the shared SPI power-task state and its sixteen halfword slots. */
#pragma dont_inline on
#include "PowerState.h"
// Original: arm7/wram @ 0x03805AD0; symbol: ARM7_InitializePowerState.
void ARM7_InitializePowerState(void)
{
 int i;
 ARM7_PowerState.initialized=1;
 ARM7_PowerState.request.operation=0;
 i=0;
 do {
  ARM7_PowerState.request.slots[i]=0;
  i++;
 } while(i<16);
}
