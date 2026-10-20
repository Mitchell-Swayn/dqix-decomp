/* Reject an address with its group bit set, then copy the three halfwords
 * into parameter state and hardware and request update flag2. */
#pragma dont_inline on
typedef struct {
    unsigned char unknown000[0x324];
    unsigned short address[3];
    unsigned char unknown32A[0x16];
    unsigned int updateFlags;
} WirelessUnicastParameterView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
extern WirelessUnicastParameterView *ARM7_WirelessUnicastParameterState;
extern void ARM7_CopyWirelessAddressHalfwords(unsigned short *destination, const unsigned short *source);
// Original: arm7/mainram @ 0x027E9174; symbol: func_027e9174; size: 0x60.
int ARM7_SetWirelessUnicastAddress(const unsigned short *source)
{
    if (*source & 1) return 5;
    ARM7_CopyWirelessAddressHalfwords(ARM7_WirelessUnicastParameterState->address, source);
    ARM7_CopyWirelessAddressHalfwords((unsigned short *)0x04808018, source);
    ARM7_WirelessUnicastParameterState->updateFlags |= 2;
    return 0;
}
