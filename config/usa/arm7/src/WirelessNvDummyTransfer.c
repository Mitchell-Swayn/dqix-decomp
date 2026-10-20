/* Clock one zero byte through the already configured SPI device. */
#pragma dont_inline on
// Original: arm7/mainram @ 0x027F59D4; symbol: func_027f59d4; size: 0x24.
void ARM7_TransferWirelessNvDummyByte(void)
{
    *(volatile unsigned short *)0x040001c2 = 0;
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
}
