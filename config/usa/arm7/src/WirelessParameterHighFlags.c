/* Additional validated wireless parameter flags and their hardware mirrors. */
#pragma dont_inline on
typedef struct {
    unsigned short bit0:1, bit1:1, bit2:1, bit3:1;
    unsigned short bit4:1, bit5:1, bit6:1, bit7:1, reserved:8;
} WirelessControlFlags;
typedef struct {
    unsigned char unknown000[0x33a];
    WirelessControlFlags flags;
} WirelessControlFlagView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
extern WirelessControlFlagView *ARM7_WirelessControlFlagState;
// Original: arm7/mainram @ 0x027E97F4; symbol: func_027e97f4; size: 0x40.
int ARM7_SetWirelessParameterFlagBitSix(unsigned int value)
{
    if (value > 1) return 5;
    ARM7_WirelessControlFlagState->flags.bit6 = (unsigned short)value;
    return 0;
}
// Original: arm7/mainram @ 0x027E9834; symbol: func_027e9834; size: 0x50.
int ARM7_SetWirelessParameterFlagBitSeven(unsigned int value)
{
    if (value > 1) return 5;
    ARM7_WirelessControlFlagState->flags.bit7 = (unsigned short)value;
    if (value == 1) *(volatile unsigned short *)0x04808028 = *(volatile unsigned short *)0x0480802a;
    return 0;
}
