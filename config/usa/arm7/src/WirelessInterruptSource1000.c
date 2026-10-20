/* Handle source 0x1000, delaying a live slot when hardware state permits. */
#pragma dont_inline on
typedef struct {
    unsigned short unknown000, mask;
    unsigned char unknown004[6]; unsigned short units;
    unsigned char unknown00C[24]; unsigned short extraUnits;
} WirelessSource1000Frame;
typedef struct {
    unsigned char unknown000[0x3c]; unsigned short active;
    unsigned char unknown03E[6]; WirelessSource1000Frame *frame;
} WirelessSource1000Slots;
typedef struct {
    unsigned char unknown000[0x400]; unsigned short delayed;
    unsigned char unknown402[0x2a]; WirelessSource1000Slots slots;
    unsigned char unknown474[0x21c]; unsigned short enabled;
} WirelessSource1000View;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
#define ARM7_WirelessSource1000State (*(WirelessSource1000View **)0x0380fff4)
extern void ARM7_EnqueueWirelessDispatchSlot(int, int);
extern void ARM7_ScheduleWirelessDelay(unsigned int, void (*)(void *));
extern void ARM7_OnWirelessDelay(void *);
// Original: arm7/wram @ 0x037FA160; symbol: func_037fa160; size: 0xf0.
void ARM7_HandleWirelessSource1000(unsigned int fromInterrupt)
{
    WirelessSource1000Slots *slots = &ARM7_WirelessSource1000State->slots;
    volatile unsigned short *registers = (volatile unsigned short *)0x04808010;
    *registers = 0x1000;
    if (slots->active) {
        if ((ARM7_WirelessSource1000State->enabled & 0x10) && fromInterrupt) {
            unsigned short pending = *(volatile unsigned short *)0x048080b6;
            unsigned int mode = *(volatile unsigned short *)0x04808214;
            if ((mode == 3 || mode == 5) && !pending) {
                int count = 0;
                WirelessSource1000Frame *frame = slots->frame;
                unsigned short mask = frame->mask;
                while (mask) {
                    count += mask & 1;
                    mask >>= 1;
                }
                ARM7_ScheduleWirelessDelay((unsigned short)(count * (frame->extraUnits + 10) + 0xc0 + (frame->units << 2)), ARM7_OnWirelessDelay);
                ARM7_WirelessSource1000State->delayed++;
                return;
            }
        }
        ARM7_EnqueueWirelessDispatchSlot(0, 16);
    }
}
