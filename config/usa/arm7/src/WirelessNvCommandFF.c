/* Issue command0xff to the nonvolatile device and wait for its SPI transfer. */
#pragma dont_inline on
// Original: arm7/mainram @ 0x027F5F9C; symbol: func_027f5f9c; size: 0x40.
void ARM7_SendWirelessNvCommandFF(void)
{
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
    *(volatile unsigned short *)0x040001c0 = 0x8100;
    *(volatile unsigned short *)0x040001c2 = 0xff;
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
}
