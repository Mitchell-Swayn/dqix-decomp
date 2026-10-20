/* Transfer an address as three halfwords, also supporting wireless hardware
 * memory where byte stores are unavailable. */
#pragma dont_inline on
// Original: arm7/mainram @ 0x027EA3F8; symbol: func_027ea3f8; size: 0x1c.
void ARM7_CopyWirelessAddressHalfwords(unsigned short *destination, const unsigned short *source)
{
    destination[0] = source[0];
    destination[1] = source[1];
    destination[2] = source[2];
}
