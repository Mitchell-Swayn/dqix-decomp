/* Reset a wireless allocation list to empty sentinels, zero its count, and
 * record the owner identifier used by wireless allocation initialization. */
#pragma dont_inline on
typedef struct {
    unsigned int first, last;
    unsigned short count, owner;
} WirelessAllocationList;
// Original: arm7/mainram @ 0x027E8F68; symbol: ARM7_InitializeWirelessAllocationList; size: 0x1c.
void ARM7_InitializeWirelessAllocationList(WirelessAllocationList *list, unsigned short owner)
{
    list->first = ~0U;
    list->last = ~0U;
    list->count = 0;
    list->owner = owner;
}
