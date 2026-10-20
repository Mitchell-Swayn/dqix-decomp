/* Add/remove allocation headers from owner-tagged wireless lists. Headers
 * retain magic 0xbf1d; removal checks the magic and owner before unlinking.
 * Count is volatile: the original decrement store is immediately reloaded
 * at 0x037F8824/0x037F8828 with no intervening aliasing write or call. */
#pragma dont_inline on
typedef struct WirelessAllocationHeader WirelessAllocationHeader;
struct WirelessAllocationHeader {
    WirelessAllocationHeader *previous, *next;
    unsigned short owner, magic;
};
typedef struct {
    WirelessAllocationHeader *first, *last;
    volatile unsigned short count;
    unsigned short owner;
} WirelessAllocationList;
extern unsigned int ARM7_DisableSpecificInterrupts(unsigned int);
extern unsigned int ARM7_EnableSpecificInterrupts(unsigned int);
// Original: arm7/wram @ 0x037F8770; symbol: ARM7_AppendWirelessAllocation; size: 0x70.
int ARM7_AppendWirelessAllocation(WirelessAllocationList *list, WirelessAllocationHeader *header)
{
    unsigned int interrupts = ARM7_DisableSpecificInterrupts(0x01000000);
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
    header->magic = 0xbf1d;
    list->last = header;
    list->count++;
    ARM7_EnableSpecificInterrupts(interrupts);
    return 0;
}
// Original: arm7/wram @ 0x037F87E0; symbol: ARM7_RemoveWirelessAllocation; size: 0xc0.
int ARM7_RemoveWirelessAllocation(WirelessAllocationList *list, WirelessAllocationHeader *header)
{
    unsigned int interrupts;
    if (header->magic != 0xbf1d) return 1;
    if (header->owner != list->owner) return 2;
    interrupts = ARM7_DisableSpecificInterrupts(0x01000000);
    list->count--;
    if (!list->count) {
        list->first = (WirelessAllocationHeader *)~0U;
        list->last = (WirelessAllocationHeader *)~0U;
    } else if (header == list->first) {
        WirelessAllocationHeader *next = header->next;
        list->first = next;
        next->previous = (WirelessAllocationHeader *)~0U;
    } else if (header == list->last) {
        WirelessAllocationHeader *previous = header->previous;
        list->last = previous;
        previous->next = (WirelessAllocationHeader *)~0U;
    } else {
        header->next->previous = header->previous;
        header->previous->next = header->next;
    }
    header->owner = 0;
    ARM7_EnableSpecificInterrupts(interrupts);
    return 0;
}
