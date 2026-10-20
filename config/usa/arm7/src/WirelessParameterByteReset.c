/* Reset the companion halfword before recording a validated byte parameter. */
#pragma dont_inline on
typedef struct {
    unsigned char unknown000[0x3c2];
    unsigned short byteAt3C2, resetAt3C4;
} WirelessByteParameterView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
extern WirelessByteParameterView *ARM7_WirelessByteParameterState;
// Original: arm7/mainram @ 0x027E9490; symbol: func_027e9490; size: 0x38.
int ARM7_SetWirelessByteParameterAndResetCompanion(unsigned short value)
{
    if (value > 255) return 5;
    ARM7_WirelessByteParameterState->resetAt3C4 = 0;
    ARM7_WirelessByteParameterState->byteAt3C2 = value;
    return 0;
}
