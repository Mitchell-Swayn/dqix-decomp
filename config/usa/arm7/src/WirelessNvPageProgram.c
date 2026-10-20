/* Issue page-program command2 within the current256-byte nonvolatile-memory page,
 * shortening a request that would cross the page boundary. */
#pragma dont_inline on
extern void ARM7_TransferWirelessNvByte(unsigned int value);
// Original: arm7/mainram @ 0x027F5C24; symbol: func_027f5c24; size: 0x10c.
void ARM7_ProgramWirelessNvPage(unsigned int offset, unsigned short size, const void *source)
{
    const unsigned char *input = (const unsigned char *)source;
    unsigned short address[3];
    int last, part, index;
    if (size < 1) return;
    if (((offset + size - 1) >> 8) > (offset >> 8)) size = 0x100 - (offset & 255);
    {
        unsigned short middle = (offset & 0xff00) >> 8;
        address[0] = (offset & 0xff0000) >> 16;
        address[1] = middle;
    }
    address[2] = offset & 255;
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
    *(volatile unsigned short *)0x040001c0 = 0x8900;
    *(volatile unsigned short *)0x040001c2 = 2;
    part = 0;
    do {
        while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
        *(volatile unsigned short *)0x040001c2 = address[part] & 255;
        part++;
    } while (part < 3);
    last = size - 1;
    for (index = 0; index < last; index++) {
        while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
        *(volatile unsigned short *)0x040001c2 = input[index];
    }
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
    *(volatile unsigned short *)0x040001c0 = 0x8100;
    ARM7_TransferWirelessNvByte(input[index]);
}
