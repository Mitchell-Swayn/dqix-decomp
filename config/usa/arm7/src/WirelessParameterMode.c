/* Bounded mode parameters in the shared wireless driver-state record. */
#pragma dont_inline on
typedef struct {
    unsigned char unknown000[0x330];
    unsigned short modeAt330;
} WirelessModeParameterView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
extern WirelessModeParameterView *ARM7_WirelessModeParameterState;
extern void ARM7_RefreshWirelessRegister8140(void);
// Original: arm7/mainram @ 0x027E92C8; symbol: func_027e92c8; size: 0x34.
int ARM7_SetWirelessModeParameterAt330(unsigned short value)
{
    if (value > 2) return 5;
    ARM7_WirelessModeParameterState->modeAt330 = value;
    ARM7_RefreshWirelessRegister8140();
    return 0;
}
