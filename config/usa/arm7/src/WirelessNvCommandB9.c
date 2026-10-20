/* Issue command0xb9 to the nonvolatile device and wait for its SPI transfer. */
#pragma dont_inline on
// Original: arm7/mainram @ 0x027F5E40; symbol: func_027f5e40; size: 0x40.
void ARM7_SendWirelessNvCommandB9(void)
{
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
    *(volatile unsigned short *)0x040001c0 = 0x8100;
    *(volatile unsigned short *)0x040001c2 = 0xb9;
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
}
