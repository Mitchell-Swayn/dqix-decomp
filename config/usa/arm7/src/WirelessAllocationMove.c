/* Move a validated header between owner lists with the wireless interrupt
 * masked across the remove and append operations. */
#pragma dont_inline on
#include "WirelessAllocationCore.h"
// Original: arm7/wram @ 0x037F89BC; symbol: func_037f89bc; size: 0x6c.
int ARM7_MoveWirelessAllocation(WirelessAllocationList *source, WirelessAllocationList *destination, WirelessAllocationHeader *header)
{
    int result;
    unsigned int interrupts;
    if (header->magic != 0xbf1d) return 1;
    interrupts = ARM7_DisableSpecificInterrupts(0x01000000);
    result = ARM7_RemoveWirelessAllocation(source, header);
    if (!result) result = ARM7_AppendValidatedWirelessAllocation(destination, header);
    ARM7_EnableSpecificInterrupts(interrupts);
    return result;
}
