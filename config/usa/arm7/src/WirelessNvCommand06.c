/* Issue command6 to the nonvolatile device and wait for its SPI transfer. */
#pragma dont_inline on
// Original: arm7/mainram @ 0x027F57BC; symbol: func_027f57bc; size: 0x40.
void ARM7_SendWirelessNvCommand06(void)
{
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
    *(volatile unsigned short *)0x040001c0 = 0x8100;
    *(volatile unsigned short *)0x040001c2 = 6;
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
}
