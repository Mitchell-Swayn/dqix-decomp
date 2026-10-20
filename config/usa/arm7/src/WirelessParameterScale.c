/* Scale the current period by a percentage, retaining0xffff as a sentinel.
 * Reject a quotient greater than0x10000 before recording the two halfwords. */
#pragma dont_inline on
typedef struct { unsigned char unknown000[0x1c]; unsigned short percentage; } WirelessScaleParameters;
typedef struct {
    unsigned char unknown000[0x6e]; unsigned short period;
    unsigned char unknown070[0x1c]; unsigned short scaled;
} WirelessScaleWorking;
typedef struct {
    unsigned char unknown000[0x31c]; WirelessScaleParameters parameters;
    unsigned char unknown33A[10]; WirelessScaleWorking working;
} WirelessScaleView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
#define ARM7_WirelessScaleState (*(WirelessScaleView **)0x0380fff4)
extern unsigned int ARM7_UnsignedDivide(unsigned int numerator, unsigned int denominator);
// Original: arm7/mainram @ 0x027EA148; symbol: func_027ea148; size: 0x64.
int ARM7_SetWirelessScaledParameter(unsigned short value)
{
    unsigned int sentinel = 0xffff;
    WirelessScaleView *state = ARM7_WirelessScaleState;
    WirelessScaleWorking *working = &state->working;
    WirelessScaleParameters *parameters = &state->parameters;
    unsigned int scaled;
    if (value == sentinel) {
        parameters->percentage = sentinel;
        working->scaled = sentinel;
    } else {
        scaled = ARM7_UnsignedDivide((unsigned int)value * working->period, 100);
        if (scaled > 0x10000) return 5;
        parameters->percentage = value;
        working->scaled = scaled;
    }
    return 0;
}
