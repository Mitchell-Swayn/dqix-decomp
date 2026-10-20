/* Initialize four priority chains and 24 dispatch slots, then enqueue slot 12
 * at priority 3. The enqueue routine at 0x037F85CC links a slot to the selected
 * chain's tail, demonstrating the endpoint and next-index fields. */
#pragma dont_inline on
typedef struct {
    unsigned short next, queued;
    void *handler;
} WirelessDispatchSlot;
typedef struct {
    volatile unsigned short heads[4], tails[4];
    unsigned short pendingPriority, activePriority;
    unsigned char unknown14[0xa8];
    WirelessDispatchSlot slots[24];
} WirelessDispatchPrefix;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
// This dispatch consumer view allocates no data or BSS.
extern WirelessDispatchPrefix *ARM7_WirelessDispatchState;
// Original: arm7/mainram @ 0x027F7560; table of 24 dispatch-handler addresses.
extern void *const ARM7_WirelessDispatchHandlers[24];
extern void ARM7_EnqueueWirelessDispatchSlot(int priority, int slot);
// Original: arm7/mainram @ 0x027E8EDC; symbol: ARM7_InitializeWirelessDispatchQueues; size: 0x8c.
void ARM7_InitializeWirelessDispatchQueues(void)
{
    WirelessDispatchPrefix *state = ARM7_WirelessDispatchState;
    unsigned int chain = 0;
    unsigned int index;
    state->pendingPriority = 0;
    state->activePriority = 0;
    do {
        state->tails[chain] = 0xffff;
        state->heads[chain] = state->tails[chain];
        chain++;
    } while (chain < 4);
    index = 0;
    do {
        state->slots[index].next = 0xffff;
        state->slots[index].queued = 0;
        state->slots[index].handler = ARM7_WirelessDispatchHandlers[index];
        index++;
    } while (index < 24);
    ARM7_EnqueueWirelessDispatchSlot(3, 12);
}
