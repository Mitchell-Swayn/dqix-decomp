/* Mirror a full hardware value and retain its half value in parameter state. */
#pragma dont_inline on
typedef struct { unsigned char unknown000[0x354]; unsigned short halfValue; } WirelessHalfValueView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
extern WirelessHalfValueView *ARM7_WirelessHalfValueState;
// Original: arm7/mainram @ 0x027E9FCC; symbol: func_027e9fcc; size: 0x2c.
int ARM7_SetWirelessHardwareValueAndHalfParameter(unsigned int value)
{
    ARM7_WirelessHalfValueState->halfValue = value >> 1;
    *(volatile unsigned short *)0x0480803c = value;
    return 0;
}
// Original: arm7/mainram @ 0x027E9FF8; symbol: func_027e9ff8; size: 0x14.
int ARM7_SetWirelessHardwareHalfwordAt8040(unsigned int value)
{
    *(volatile unsigned short *)0x04808040 = value;
    return 0;
}
