/* Copy a six-byte wireless address to driver state and hardware, then update
 * the hardware-control bit from the low bit of the address. */
#pragma dont_inline on
typedef struct {
    unsigned char unknown000[0x3a8];
    unsigned short address[3];
} WirelessAddressParameterView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
extern WirelessAddressParameterView *ARM7_WirelessAddressParameterState;
extern void ARM7_CopyWirelessAddressHalfwords(unsigned short *destination, const unsigned short *source);
// Original: arm7/mainram @ 0x027E9884; symbol: func_027e9884; size: 0x64.
int ARM7_SetWirelessAddressParameter(const unsigned short *source)
{
    ARM7_CopyWirelessAddressHalfwords(ARM7_WirelessAddressParameterState->address, source);
    ARM7_CopyWirelessAddressHalfwords((unsigned short *)0x04808020, source);
    if (*source & 1) *(volatile unsigned short *)0x048080d0 &= ~0x400;
    else *(volatile unsigned short *)0x048080d0 |= 0x400;
    return 0;
}
