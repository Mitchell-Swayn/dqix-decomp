/* Append a dispatch slot once to a priority chain under the wireless IRQ mask.
 * Work arriving while priority 3 is active wakes the external worker queue.
 * Volatile views retain reads/writes of dispatch state shared with IRQ work. */
#pragma dont_inline on
#include "MessageQueue.h"
typedef struct {
    unsigned short next, queued;
    void *handler;
} WirelessDispatchSlot;
typedef struct {
    volatile unsigned short heads[4], tails[4];
    unsigned short pendingPriority, activePriority;
    unsigned char unknown14[0xa8];
    WirelessDispatchSlot slots[24];
    unsigned char unknown17C[0x18c];
    MessageQueue *queue;
} WirelessDispatchQueueView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
extern WirelessDispatchQueueView *ARM7_WirelessDispatchQueueState;
extern unsigned int ARM7_DisableSpecificInterrupts(unsigned int);
extern unsigned int ARM7_EnableSpecificInterrupts(unsigned int);
extern int ARM7_SendMessage(MessageQueue *, void *, int);
// Original: arm7/wram @ 0x037F85CC; symbol: ARM7_EnqueueWirelessDispatchSlot; size: 0xb8.
void ARM7_EnqueueWirelessDispatchSlot(int priority, int slot)
{
    volatile WirelessDispatchQueueView *state = ARM7_WirelessDispatchQueueState;
    volatile WirelessDispatchSlot *slots = state->slots;
    unsigned int interrupts = ARM7_DisableSpecificInterrupts(0x01000010);
    if (!slots[slot].queued) {
        unsigned short last;
        slots[slot].queued = 1;
        slots[slot].next = 0xffff;
        last = state->tails[priority];
        if (last == 0xffff) state->heads[priority] = slot;
        else state->slots[last].next = slot;
        state->tails[priority] = slot;
        if (priority < state->pendingPriority) state->pendingPriority = priority;
    }
    ARM7_EnableSpecificInterrupts(interrupts);
    if (priority != 3 && state->activePriority == 3)
        ARM7_SendMessage(ARM7_WirelessDispatchQueueState->queue, 0, 0);
}
