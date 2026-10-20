/* Parameter bit4 selects a policy for bit5. Policy0 stores the supplied
 * boolean; policy1 requires main mode1 and clears bit5. Mirror bit3 XOR bit5. */
#pragma dont_inline on
typedef struct {
    unsigned short bit0:1, bit1:1, bit2:1, bit3:1, bit4:1, bit5:1, reserved:10;
} WirelessPolicyFlags;
typedef struct {
    unsigned char unknown000[0x12]; unsigned short mode;
    unsigned char unknown014[10]; WirelessPolicyFlags flags;
} WirelessPolicyParameters;
typedef struct { unsigned char unknown000[0x31c]; WirelessPolicyParameters parameters; } WirelessFlagPolicyView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
#define ARM7_WirelessFlagPolicyState (*(WirelessFlagPolicyView **)0x0380fff4)
// Original: arm7/mainram @ 0x027E9720; symbol: func_027e9720; size: 0xd4.
int ARM7_SetWirelessParameterFlagPolicy(unsigned int policy, unsigned int value)
{
    if (policy > 1 || value > 1) return 5;
    switch (policy) {
    case 0:
        ARM7_WirelessFlagPolicyState->parameters.flags.bit5 = (unsigned short)value;
        break;
    case 1:
        if (ARM7_WirelessFlagPolicyState->parameters.mode != 1) return 11;
        ARM7_WirelessFlagPolicyState->parameters.flags.bit5 = 0;
        break;
    }
    {
        WirelessPolicyParameters *parameters = &ARM7_WirelessFlagPolicyState->parameters;
        parameters->flags.bit4 = (unsigned short)policy;
    }
    *(volatile unsigned short *)0x04808290 = ARM7_WirelessFlagPolicyState->parameters.flags.bit5 ^ ARM7_WirelessFlagPolicyState->parameters.flags.bit3;
    return 0;
}
