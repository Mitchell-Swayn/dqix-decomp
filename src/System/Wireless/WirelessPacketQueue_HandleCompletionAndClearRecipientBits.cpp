#include <globaldefs.h>
#pragma opt_propagation off
#include <System/Interrupts.h>
#pragma optimize_for_size off
struct EventPacket { unsigned short mask; char pad[510]; };
struct EventQueue {
    EventPacket packets[4];
    char pad800[8];
    unsigned short current;
    char pad80a[0x818-0x80a];
    unsigned short paired;
    char pad81a[2];
    unsigned short status;
};
struct EventNotification {
    unsigned short unknown, error, type;
    char pad6[6];
    unsigned value;
    char pad10[2];
    unsigned short bit;
    char pad14[8];
    EventQueue *queue;
};
extern "C" void CopySelectedEnabledBitBlockToDestination(EventQueue *,unsigned short,unsigned);
extern "C" void WirelessPacketQueue_AdvanceAndSubmitEmptyCurrentPacket(EventQueue *,int);
// Original: arm9/main @ 0x020D63F0; symbol: func_020d63f0; size: 0x12C.
extern "C" void WirelessPacketQueue_HandleCompletionAndClearRecipientBits(EventNotification *event) {
    EventQueue *queue = event->queue;
    if (!queue) return;
    if (!event->error) {
        switch (event->type) {
        case 21:
            CopySelectedEnabledBitBlockToDestination(queue,event->bit,event->value);
            WirelessPacketQueue_AdvanceAndSubmitEmptyCurrentPacket(queue,0);
            return;
        case 7:
            WirelessPacketQueue_AdvanceAndSubmitEmptyCurrentPacket(queue,0);
            return;
        case 25:
            return;
        case 9:
        case 26: {
            unsigned bit = event->bit;
            unsigned one = 1;
            int irq = DisableIRQInterrupts();
            unsigned short current = queue->current;
            unsigned mask = ~(one << bit);
            queue->packets[current].mask &= mask;
            if (queue->paired == 1) {
                unsigned short next = (current + 1) & 3;
                queue->packets[next].mask &= mask;
            }
            SetIRQInterruptState(irq);
            WirelessPacketQueue_AdvanceAndSubmitEmptyCurrentPacket(queue,0);
            if (queue->paired != 1) return;
            WirelessPacketQueue_AdvanceAndSubmitEmptyCurrentPacket(queue,0);
            return;
        }
        default: return;
        }
    }
    queue->status = 5;
}
