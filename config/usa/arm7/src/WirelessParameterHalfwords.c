/* Copy sixteen halfwords into the wireless parameter block at offset 0x384. */
#pragma dont_inline on
typedef struct {
    unsigned char unknown000[0x384];
    unsigned short parameters[16];
} WirelessHalfwordParameterView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
extern WirelessHalfwordParameterView *ARM7_WirelessHalfwordParameterState;
// Original: arm7/mainram @ 0x027E9578; symbol: func_027e9578; size: 0x30.
int ARM7_CopyWirelessHalfwordParameters(const unsigned short *source)
{
    unsigned short *destination = ARM7_WirelessHalfwordParameterState->parameters;
    unsigned int index = 0;
    do {
        *destination++ = *source++;
        index++;
    } while (index < 16);
    return 0;
}
