/* Read a byte range with SPI command3 and a three-byte big-endian address.
 * Keep the device selected through all but the final received byte. */
#pragma dont_inline on
extern void ARM7_TransferWirelessNvDummyByte(void);
// Original: arm7/mainram @ 0x027F58D0; symbol: ARM7_ReadWirelessNvByteRange; size: 0x104.
void ARM7_ReadWirelessNvByteRange(unsigned int offset, unsigned int size, void *destination)
{
    unsigned char *output = (unsigned char *)destination;
    unsigned short address[3];
    int part;
    unsigned int index;
    if (size < 1) return;
    {
    unsigned short middle = (offset & 0xff00) >> 8;
    address[0] = (offset & 0xff0000) >> 16;
    address[1] = middle;
    }
    address[2] = offset & 255;
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
    *(volatile unsigned short *)0x040001c0 = 0x8900;
    *(volatile unsigned short *)0x040001c2 = 3;
    part = 0;
    do {
        while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
        *(volatile unsigned short *)0x040001c2 = address[part] & 255;
        part++;
    } while (part < 3);
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
    for (index = 0; index < size - 1; index++) {
        *(volatile unsigned short *)0x040001c2 = 0;
        while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
        output[index] = *(volatile unsigned short *)0x040001c2;
    }
    *(volatile unsigned short *)0x040001c0 = 0x8100;
    ARM7_TransferWirelessNvDummyByte();
    output[index] = *(volatile unsigned short *)0x040001c2;
}
