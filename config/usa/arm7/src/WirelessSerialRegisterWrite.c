/* Write both halves of a wireless serial-register command and return the
 * serial-busy polling result. */
#pragma dont_inline on
extern int ARM7_WaitWirelessSerialRegisterReady(void);
// Original: arm7/mainram @ 0x027EA938; symbol: func_027ea938; size: 0x20.
int ARM7_WriteWirelessSerialWord(unsigned int value)
{
    *(volatile unsigned short *)0x0480817e = value;
    *(volatile unsigned short *)0x0480817c = value >> 16;
    return ARM7_WaitWirelessSerialRegisterReady();
}
