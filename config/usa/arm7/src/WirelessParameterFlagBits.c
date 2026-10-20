/* Two independently validated bit fields of the wireless parameter flags. */
#pragma dont_inline on
typedef struct {
    unsigned short bit0:1, bit1:1, bit2:1, bit3:1;
    unsigned short bit4:1, bit5:1, bit6:1, bit7:1, reserved:8;
} WirelessParameterFlags;
typedef struct {
    unsigned char unknown000[0x33a];
    WirelessParameterFlags flags;
} WirelessFlagParameterView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
extern WirelessFlagParameterView *ARM7_WirelessFlagParameterState;
// Original: arm7/mainram @ 0x027E9420; symbol: func_027e9420; size: 0x38.
int ARM7_SetWirelessParameterFlagBitZero(unsigned short value)
{
    if (value > 1) return 5;
    ARM7_WirelessFlagParameterState->flags.bit0 = value;
    return 0;
}
// Original: arm7/mainram @ 0x027E9458; symbol: func_027e9458; size: 0x38.
int ARM7_SetWirelessParameterFlagBitOne(unsigned short value)
{
    if (value > 1) return 5;
    ARM7_WirelessFlagParameterState->flags.bit1 = value;
    return 0;
}
