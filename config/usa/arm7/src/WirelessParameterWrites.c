/* Validate and store two driver parameters. Their wider policy remains unknown:
 * offset 0x32a accepts a byte and mirrors it to the hardware halfword register;
 * offset 0x32c requires at least one bit from 0x7ffe and marks update flag 4. */
#pragma dont_inline on
typedef struct {
    unsigned char prefix[0x32a];
    unsigned short byteParameter, maskedParameter;
    unsigned char unknown32E[0x12];
    unsigned int updateFlags;
} WirelessParameterView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
extern WirelessParameterView *ARM7_WirelessParameterState;
// Original: arm7/mainram @ 0x027E91D4; symbol: ARM7_SetWirelessByteParameterAtOffset32A; size: 0x34.
int ARM7_SetWirelessByteParameterAtOffset32A(unsigned short value)
{
    if (value > 255) return 5;
    ARM7_WirelessParameterState->byteParameter = value;
    *(volatile unsigned short *)0x0480802c = value;
    return 0;
}
// Original: arm7/mainram @ 0x027E9208; symbol: ARM7_SetWirelessMaskedParameterAtOffset32C; size: 0x40.
int ARM7_SetWirelessMaskedParameterAtOffset32C(unsigned int value)
{
    if (!(value & 0x7ffe)) return 5;
    ARM7_WirelessParameterState->maskedParameter = value;
    ARM7_WirelessParameterState->updateFlags |= 4;
    return 0;
}
