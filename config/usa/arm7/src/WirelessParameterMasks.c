/* Preserve the first mask and combine both supplied masks before refreshing
 * the dependent wireless timing register. */
#pragma dont_inline on
typedef struct { unsigned short first, combined; } WirelessMaskPair;
typedef struct { unsigned char unknown000[0x3a4]; WirelessMaskPair masks; } WirelessMaskParameterView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
extern WirelessMaskParameterView *ARM7_WirelessMaskParameterState;
extern void ARM7_RefreshWirelessRegister8140(void);
// Original: arm7/mainram @ 0x027E9EA4; symbol: func_027e9ea4; size: 0x40.
int ARM7_SetWirelessCombinedParameterMasks(const unsigned short *source)
{
    WirelessMaskParameterView *state = ARM7_WirelessMaskParameterState;
    WirelessMaskPair *masks = &state->masks;
    state->masks.first = source[0];
    masks->combined = source[1] | source[0];
    ARM7_RefreshWirelessRegister8140();
    return 0;
}
