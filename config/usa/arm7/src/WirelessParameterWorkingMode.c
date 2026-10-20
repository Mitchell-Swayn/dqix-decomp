/* Update a working mode and two dependent flags, mirror the live-frame flag
 * in the active case, and replace hardware control bits3 through5. */
#pragma dont_inline on
typedef struct {
    unsigned char unknown000[8]; unsigned short status;
    unsigned char unknown00A[0x72]; unsigned short flags;
    unsigned char unknown07E[12]; unsigned short secondaryFlags;
} WirelessWorkingModeBlock;
typedef struct {
    unsigned char unknown000[0x334]; unsigned short mode;
    unsigned char unknown336[14]; WirelessWorkingModeBlock working;
    unsigned char unknown3D0[0xdc]; unsigned char *frame;
} WirelessWorkingModeView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
extern WirelessWorkingModeView *ARM7_WirelessWorkingModeState;
// Original: arm7/mainram @ 0x027E92FC; symbol: func_027e92fc; size: 0xa0.
int ARM7_SetWirelessWorkingModeParameter(unsigned short value)
{
    WirelessWorkingModeView *state = ARM7_WirelessWorkingModeState;
    WirelessWorkingModeBlock *working = &state->working;
    if (value > 3) return 5;
    state->mode = value;
    if (!value) {
        working->flags &= ~0x10;
        working->secondaryFlags &= ~0x4000;
    } else {
        working->flags |= 0x10;
        working->secondaryFlags |= 0x4000;
    }
    if (working->status == 0x40 && value == 1)
        *(unsigned short *)(ARM7_WirelessWorkingModeState->frame + 0x2e) = working->flags;
    if (!value) value = 1;
    *(volatile unsigned short *)0x04808006 = (*(volatile unsigned short *)0x04808006 & 0xffc7) | (value << 3);
    return 0;
}
