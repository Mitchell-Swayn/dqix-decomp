/* Sixteen halfwords assemble incoming nonvolatile-memory service commands.
 * The receiving callback uses the packet index's low four bits to select a slot. */
#pragma dont_inline on
// Original: arm7/mainram BSS @ 0x027F94EC; symbol: ARM7_WirelessNvCommandHalfwords; size: 0x20.
unsigned short ARM7_WirelessNvCommandHalfwords[16];
// Original: arm7/mainram @ 0x027F52C4; symbol: func_027f52c4; size: 0x28.
void ARM7_ClearWirelessNvCommandHalfwords(void)
{
    int index = 0;
    do {
        ARM7_WirelessNvCommandHalfwords[index] = 0;
        index++;
    } while (index < 16);
}
