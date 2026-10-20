/* Record the secondary mode and derive control bit0x40 from it and the main
 * mode. Clearing the control bit also refreshes the current interval bytes. */
#pragma dont_inline on
typedef struct {
    unsigned char unknown000[0x12]; unsigned short mode;
    unsigned char unknown014[0x0c]; unsigned short interval;
} WirelessSecondaryParameters;
typedef struct {
    unsigned char unknown000[0x31c]; WirelessSecondaryParameters parameters;
    unsigned char unknown33E[0x14]; unsigned short secondaryMode;
} WirelessSecondaryModeView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
extern WirelessSecondaryModeView *ARM7_WirelessSecondaryModeState;
extern int ARM7_SetWirelessInterval(unsigned short value, int mirrorToHardware);
// Original: arm7/mainram @ 0x027E9F64; symbol: ARM7_SetWirelessSecondaryMode; size: 0x68.
int ARM7_SetWirelessSecondaryMode(unsigned short value)
{
    WirelessSecondaryModeView *state = ARM7_WirelessSecondaryModeState;
    WirelessSecondaryParameters *parameters = &state->parameters;
    state->secondaryMode = value;
    if (value && parameters->mode != 1) *(volatile unsigned short *)0x04808006 |= 0x40;
    else {
        *(volatile unsigned short *)0x04808006 &= ~0x40;
        ARM7_SetWirelessInterval(parameters->interval, 0);
    }
    return 0;
}
