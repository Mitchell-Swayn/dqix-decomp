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
#define ARM7_WirelessControlFlagState (*(WirelessControlFlagView **)0x0380fff4)
// Original: arm7/mainram @ 0x027E96B8; symbol: func_027e96b8; size: 0x68.
int ARM7_SetWirelessParameterFlagBitThree(unsigned int value)
{
    if (value > 1) return 5;
    {
        unsigned short narrowed = (unsigned short)value;
        ARM7_WirelessControlFlagState->flags.bit3 = narrowed;
    }
    *(volatile unsigned short *)0x04808290 = ARM7_WirelessControlFlagState->flags.bit5 ^ ARM7_WirelessControlFlagState->flags.bit3;
    return 0;
}
