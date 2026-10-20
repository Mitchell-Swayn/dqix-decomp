/* Issue command0xc7 to the nonvolatile device and wait for its SPI transfer. */
#pragma dont_inline on
// Original: arm7/mainram @ 0x027F5EC0; symbol: func_027f5ec0; size: 0x40.
void ARM7_SendWirelessNvCommandC7(void)
{
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
    *(volatile unsigned short *)0x040001c0 = 0x8100;
    *(volatile unsigned short *)0x040001c2 = 0xc7;
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
}
