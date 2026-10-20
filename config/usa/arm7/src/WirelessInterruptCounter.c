/* Acknowledge the 0x8000 wireless source and advance the matching-frame timer. */
#pragma dont_inline on
typedef struct {
    unsigned char unknown000[8]; unsigned short status;
    unsigned char unknown00A[6]; unsigned short request;
    unsigned char unknown012[0x5e]; unsigned short expected, observed;
    unsigned char unknown074[10]; unsigned short limit;
    volatile unsigned short counter;
} WirelessInterruptWorking;
typedef struct { unsigned char unknown000[0x344]; WirelessInterruptWorking working; } WirelessInterruptCounterView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
#define ARM7_WirelessInterruptCounterState (*(WirelessInterruptCounterView **)0x0380fff4)
extern void ARM7_EnqueueWirelessDispatchSlot(int priority, int slot);
// Original: arm7/wram @ 0x037F93E4; symbol: func_037f93e4; size: 0x8c.
void ARM7_HandleWirelessCounterInterrupt(void)
{
    WirelessInterruptWorking *working;
    volatile unsigned short *interruptFlags;
    WirelessInterruptCounterView *state = ARM7_WirelessInterruptCounterState;
    interruptFlags = (volatile unsigned short *)0x04808010;
    *interruptFlags = 0x8000;
    working = &state->working;
    if (working->status == 0x40 && working->limit && working->observed == working->expected) {
        /* The original IRQ body stores 0x037F9430 then reloads 0x037F9434.
         * The same counter is cleared by the ordinary parameter setter at
         * 0x027E94AC. This member is shared with the registered IRQ callback. */
        working->counter++;
        if (working->counter > working->limit) {
            working->counter = 0;
            ARM7_EnqueueWirelessDispatchSlot(1, 13);
        }
    }
    working->request = 1;
}
