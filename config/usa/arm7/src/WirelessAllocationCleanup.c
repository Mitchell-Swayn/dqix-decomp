/* Free each allocation from the eight lists at driver-state offsets
 * 0x194..0x1e8. Each link's next pointer is saved before its buffer is freed;
 * a nonempty chain terminates with the same -1 sentinel as an empty list. */
#pragma dont_inline on
typedef struct WirelessAllocationNode WirelessAllocationNode;
struct WirelessAllocationNode { WirelessAllocationNode *previous, *next; };
typedef struct {
    WirelessAllocationNode *first, *last;
    unsigned short count, owner;
} WirelessAllocationList;
typedef struct {
    unsigned char prefix[0x194];
    WirelessAllocationList lists[8];
} WirelessAllocationCleanupState;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
// This cleanup consumer view defines no additional storage.
extern WirelessAllocationCleanupState *ARM7_WirelessAllocationCleanupState;
extern int ARM7_FreeWirelessAllocation(WirelessAllocationList *, WirelessAllocationNode *);
void ARM7_ClearWirelessAllocationList(WirelessAllocationList *);
// Original: arm7/mainram @ 0x027E905C; symbol: ARM7_ClearWirelessAllocationLists; size: 0x58.
void ARM7_ClearWirelessAllocationLists(void)
{
    WirelessAllocationCleanupState *state = ARM7_WirelessAllocationCleanupState;
    ARM7_ClearWirelessAllocationList(&state->lists[0]);
    ARM7_ClearWirelessAllocationList(&state->lists[1]);
    ARM7_ClearWirelessAllocationList(&state->lists[2]);
    ARM7_ClearWirelessAllocationList(&state->lists[3]);
    ARM7_ClearWirelessAllocationList(&state->lists[4]);
    ARM7_ClearWirelessAllocationList(&state->lists[5]);
    ARM7_ClearWirelessAllocationList(&state->lists[6]);
    ARM7_ClearWirelessAllocationList(&state->lists[7]);
}
// Original: arm7/mainram @ 0x027E90B4; symbol: ARM7_ClearWirelessAllocationList; size: 0x40.
void ARM7_ClearWirelessAllocationList(WirelessAllocationList *list)
{
    WirelessAllocationNode *node = list->first;
    if (list->count) {
        while (node != (WirelessAllocationNode *)~0U) {
            WirelessAllocationNode *next = node->next;
            ARM7_FreeWirelessAllocation(list, node);
            node = next;
        }
    }
}
