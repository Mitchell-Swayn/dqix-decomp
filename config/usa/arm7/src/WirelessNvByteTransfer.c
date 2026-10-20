/* Transfer the low byte of a value through the configured SPI device. */
#pragma dont_inline on
// Original: arm7/mainram @ 0x027F57FC; symbol: func_027f57fc; size: 0x24.
void ARM7_TransferWirelessNvByte(unsigned int value)
{
    *(volatile unsigned short *)0x040001c2 = value & 255;
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
}
