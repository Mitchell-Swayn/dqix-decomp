/* Require the wireless allocation magic and no existing owner before linking
 * a header at the tail and assigning the list's owner identifier. */
#pragma dont_inline on
#include "WirelessAllocationCore.h"
// Original: arm7/wram @ 0x037F8A28; symbol: func_037f8a28; size: 0x8c.
int ARM7_AppendValidatedWirelessAllocation(WirelessAllocationList *list, WirelessAllocationHeader *header)
{
    unsigned int interrupts;
    if (header->magic != 0xbf1d) return 1;
    if (header->owner) return 2;
    interrupts = ARM7_DisableSpecificInterrupts(0x01000000);
    if (!list->count) {
        header->previous = (WirelessAllocationHeader *)~0U;
        list->first = header;
    } else {
        WirelessAllocationHeader *previous = list->last;
        header->previous = previous;
        previous->next = header;
    }
    header->next = (WirelessAllocationHeader *)~0U;
    header->owner = list->owner;
    list->last = header;
    list->count++;
    ARM7_EnableSpecificInterrupts(interrupts);
    return 0;
}
// Original: arm7/wram @ 0x037F8AB4; symbol: func_037f8ab4; size: 0x8.
WirelessAllocationHeader *ARM7_GetNextWirelessAllocation(const WirelessAllocationHeader *header)
{
    return header->next;
}
