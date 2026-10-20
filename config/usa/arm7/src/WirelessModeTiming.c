/* Select timing value10 for mode1 or mode0 with first-mask bit0 set;
 * all other combinations select20. */
#pragma dont_inline on
typedef struct {
    unsigned char unknown000[0x330];
    unsigned short mode;
    unsigned char unknown332[0x72];
    unsigned short firstMask;
} WirelessModeTimingView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
extern WirelessModeTimingView *ARM7_WirelessModeTimingState;
// Original: arm7/mainram @ 0x027EA890; symbol: func_027ea890; size: 0x4c.
unsigned int ARM7_GetWirelessModeTimingValue(void)
{
    WirelessModeTimingView *state = ARM7_WirelessModeTimingState;
    switch (state->mode) {
    case 0: if (state->firstMask & 1) return 10; break;
    case 1: return 10;
    }
    return 20;
}
