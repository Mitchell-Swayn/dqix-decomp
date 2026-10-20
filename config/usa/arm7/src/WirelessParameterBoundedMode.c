/* Validate the two-bit parameter at offset 0x336. */
#pragma dont_inline on
typedef struct {
    unsigned char unknown000[0x336];
    unsigned short modeAt336;
} WirelessBoundedModeView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
extern WirelessBoundedModeView *ARM7_WirelessBoundedModeState;
// Original: arm7/mainram @ 0x027E939C; symbol: func_027e939c; size: 0x24.
int ARM7_SetWirelessModeParameterAt336(unsigned short value)
{
    if (value > 3) return 5;
    ARM7_WirelessBoundedModeState->modeAt336 = value;
    return 0;
}
