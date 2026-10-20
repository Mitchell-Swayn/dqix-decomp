/* Read status command5 from the nonvolatile memory over hardware SPI, with
 * the device selected continuously until the final receive byte. */
#pragma dont_inline on
// Original: arm7/mainram @ 0x027F5860; symbol: func_027f5860; size: 0x70.
void ARM7_ReadWirelessNvStatusByte(unsigned char *status)
{
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
    *(volatile unsigned short *)0x040001c0 = 0x8900;
    *(volatile unsigned short *)0x040001c2 = 5;
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
    *(volatile unsigned short *)0x040001c0 = 0x8100;
    *(volatile unsigned short *)0x040001c2 = 0;
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
    *status = *(volatile unsigned short *)0x040001c2;
}
