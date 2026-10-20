/* Two halfword parameters each accept the byte range1 through255. */
#pragma dont_inline on
typedef struct {
    unsigned char unknown000[0x3b4]; unsigned short parameterAt3B4, unknown3B6, parameterAt3B8;
} WirelessNonzeroByteView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
extern WirelessNonzeroByteView *ARM7_WirelessNonzeroByteState;
// Original: arm7/mainram @ 0x027E9A50; symbol: func_027e9a50; size: 0x44.
int ARM7_SetWirelessNonzeroByteAndClearHardwareCompanion(unsigned short value)
{
    if (value < 1 || value > 255) return 5;
    ARM7_WirelessNonzeroByteState->parameterAt3B8 = value;
    *(volatile unsigned short *)0x0480808e = value;
    *(volatile unsigned short *)0x04808088 = 0;
    return 0;
}
// Original: arm7/mainram @ 0x027E9A94; symbol: func_027e9a94; size: 0x34.
int ARM7_SetWirelessNonzeroByteParameterAt3B4(unsigned short value)
{
    if (value < 1 || value > 255) return 5;
    ARM7_WirelessNonzeroByteState->parameterAt3B4 = value;
    return 0;
}
