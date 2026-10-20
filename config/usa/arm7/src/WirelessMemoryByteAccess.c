/* Read and replace individual bytes through halfword accesses suitable for
 * wireless hardware memory. The other byte in a written halfword survives. */
#pragma dont_inline on
// Original: arm7/mainram @ 0x027EB03C; symbol: func_027eb03c; size: 0x2c.
void ARM7_WriteWirelessMemoryByte(unsigned char *destination, unsigned int value)
{
    if ((unsigned int)destination & 1) {
        unsigned short *halfword = (unsigned short *)(destination - 1);
        *halfword = (*halfword & 255) | (value << 8);
    } else {
        unsigned short *halfword = (unsigned short *)destination;
        *halfword = (*halfword & 0xff00) | (value & 255);
    }
}
// Original: arm7/mainram @ 0x027EB068; symbol: func_027eb068; size: 0x1c.
unsigned char ARM7_ReadWirelessMemoryByte(const unsigned char *source)
{
    unsigned char value;
    if ((unsigned int)source & 1) value = *(unsigned short *)(source - 1) >> 8;
    else value = *(unsigned short *)source;
    return value & 255;
}
