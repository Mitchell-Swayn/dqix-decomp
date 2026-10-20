/* Issue an indexed wireless-register write and map a busy timeout to -1. */
#pragma dont_inline on
extern int ARM7_WaitWirelessIndexedRegisterReady(void);
// Original: arm7/mainram @ 0x027EA908; symbol: func_027ea908; size: 0x30.
int ARM7_WriteWirelessIndexedRegister(unsigned int index, unsigned int value)
{
    *(volatile unsigned short *)0x0480815a = value;
    *(volatile unsigned short *)0x04808158 = index | 0x5000;
    return ARM7_WaitWirelessIndexedRegisterReady() ? ~0U : 0;
}
