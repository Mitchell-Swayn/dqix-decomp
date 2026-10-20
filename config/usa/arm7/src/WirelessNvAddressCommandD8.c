/* Send command0xd8 followed by the three address bytes, releasing the SPI
 * device selection while transferring the low address byte. */
#pragma dont_inline on
extern void ARM7_TransferWirelessNvByte(unsigned int value);
// Original: arm7/mainram @ 0x027F5DB8; symbol: func_027f5db8; size: 0x88.
void ARM7_SendWirelessNvAddressCommandD8(unsigned int offset)
{
    unsigned short high = (offset & 0xff0000) >> 16;
    unsigned short middle = (offset & 0xff00) >> 8;
    unsigned short low = offset & 255;
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
    *(volatile unsigned short *)0x040001c0 = 0x8900;
    *(volatile unsigned short *)0x040001c2 = 0xd8;
    while (*(volatile unsigned short *)0x040001c0 & 0x80) {}
    ARM7_TransferWirelessNvByte(high);
    ARM7_TransferWirelessNvByte(middle);
    *(volatile unsigned short *)0x040001c0 = 0x8100;
    ARM7_TransferWirelessNvByte(low);
}
