/* Mirror validated parameter bit2 to the working flag and hardware control,
 * and refresh the live frame and derived timing value when applicable. */
#pragma dont_inline on
typedef struct { unsigned short bit0:1, bit1:1, bit2:1, reserved:13; } WirelessBitTwoFlags;
typedef struct {
    unsigned char unknown000[8]; unsigned short status;
    unsigned char unknown00A[0x72]; unsigned short flags;
} WirelessBitTwoWorking;
typedef struct {
    unsigned char unknown000[0x32e]; unsigned short mode;
    unsigned char unknown330[10]; WirelessBitTwoFlags parameterFlags;
    unsigned char unknown33C[8]; WirelessBitTwoWorking working;
    unsigned char unknown3C2[0xea]; unsigned char *frame;
} WirelessBitTwoView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
extern WirelessBitTwoView *ARM7_WirelessBitTwoState;
extern void ARM7_RefreshWirelessRegister8140(void);
// Original: arm7/mainram @ 0x027E95A8; symbol: func_027e95a8; size: 0xa8.
int ARM7_SetWirelessParameterFlagBitTwo(unsigned short value)
{
    WirelessBitTwoView *state = ARM7_WirelessBitTwoState;
    WirelessBitTwoWorking *working = &state->working;
    if (value > 1) return 5;
    state->parameterFlags.bit2 = value;
    if (!value) working->flags &= ~0x20;
    else working->flags |= 0x20;
    if (working->status == 0x40 && ARM7_WirelessBitTwoState->mode == 1)
        *(unsigned short *)(ARM7_WirelessBitTwoState->frame + 0x2e) = working->flags;
    if (!value) *(volatile unsigned short *)0x048080bc &= ~6;
    else *(volatile unsigned short *)0x048080bc |= 6;
    ARM7_RefreshWirelessRegister8140();
    return 0;
}
