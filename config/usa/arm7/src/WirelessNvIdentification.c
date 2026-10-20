/* Issue identification command0x9f and return the two received bytes. */
#pragma dont_inline on
// Original: arm7/mainram @ 0x027F5F00; symbol: func_027f5f00; size: 0x9c.
void ARM7_ReadWirelessNvIdentificationBytes(unsigned char *destination)
{
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
    *(volatile unsigned short *)0x040001c0 = 0x8900;
    *(volatile unsigned short *)0x040001c2 = 0x9f;
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
    *(volatile unsigned short *)0x040001c2 = 0;
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
    destination[0] = *(volatile unsigned short *)0x040001c2;
    *(volatile unsigned short *)0x040001c0 = 0x8100;
    *(volatile unsigned short *)0x040001c2 = 0;
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
    destination[1] = *(volatile unsigned short *)0x040001c2;
}
