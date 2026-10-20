/* Remove the first slot from a priority chain while the wireless IRQ sources
 * are masked. A 0xffff slot marks an empty chain. The removed slot's queued
 * flag is cleared and its next index is restored to the sentinel. */
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
extern WirelessDispatchPrefix *ARM7_WirelessDispatchDequeueState;
extern unsigned int ARM7_DisableSpecificInterrupts(unsigned int);
extern unsigned int ARM7_EnableSpecificInterrupts(unsigned int);
// Original: arm7/wram @ 0x037F8684; symbol: ARM7_DequeueWirelessDispatchSlot; size: 0x78.
unsigned short ARM7_DequeueWirelessDispatchSlot(int priority)
{
    WirelessDispatchPrefix *state = ARM7_WirelessDispatchDequeueState;
    unsigned int interrupts = ARM7_DisableSpecificInterrupts(0x01000010);
    unsigned short slot = state->heads[priority];
    if (slot != 0xffff) {
        WirelessDispatchSlot *slots = state->slots;
        unsigned short next;
        slots[slot].queued = 0;
        next = slots[slot].next;
        if (next == 0xffff) {
            state->heads[priority] = 0xffff;
            state->tails[priority] = 0xffff;
        } else {
            state->heads[priority] = next;
            slots[slot].next = 0xffff;
        }
    }
    ARM7_EnableSpecificInterrupts(interrupts);
    return slot;
}
