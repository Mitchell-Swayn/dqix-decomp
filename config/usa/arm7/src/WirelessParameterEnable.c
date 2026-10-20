/* Validate the boolean parameter held as a halfword at offset0x332. */
#pragma dont_inline on
typedef struct { unsigned char unknown000[0x332]; unsigned short enabled; } WirelessEnableParameterView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
extern WirelessEnableParameterView *ARM7_WirelessEnableParameterState;
// Original: arm7/mainram @ 0x027E9650; symbol: func_027e9650; size: 0x24.
int ARM7_SetWirelessEnableParameterAt332(unsigned short value)
{
    if (value > 1) return 5;
    ARM7_WirelessEnableParameterState->enabled = value;
    return 0;
}
