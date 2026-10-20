/* Accept a period from10 through1000, mirror it to hardware, and recompute
 * the existing scaled parameter against the new period. */
#pragma dont_inline on
typedef struct {
    unsigned char unknown000[0x338]; unsigned short scale;
    unsigned char unknown33A[0x78]; unsigned short period;
} WirelessPeriodParameterView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
#define ARM7_WirelessPeriodParameterState (*(WirelessPeriodParameterView **)0x0380fff4)
extern int ARM7_SetWirelessScaledParameter(unsigned short value);
// Original: arm7/mainram @ 0x027E99F8; symbol: func_027e99f8; size: 0x58.
int ARM7_SetWirelessBoundedPeriod(unsigned short value)
{
    if (value < 10 || value > 1000) return 5;
    ARM7_WirelessPeriodParameterState->period = value;
    *(volatile unsigned short *)0x0480808c = value;
    ARM7_SetWirelessScaledParameter(ARM7_WirelessPeriodParameterState->scale);
    return 0;
}
