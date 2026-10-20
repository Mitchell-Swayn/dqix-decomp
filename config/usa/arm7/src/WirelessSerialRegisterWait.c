/* Poll the wireless serial-register busy bit for at most0x2800 reads. */
#pragma dont_inline on
// Original: arm7/wram @ 0x037FB488; symbol: func_037fb488; size: 0x34.
int ARM7_WaitWirelessSerialRegisterReady(void)
{
    unsigned int count = 0;
    for (; count < 0x2800; count++)
        if (!(*(volatile unsigned short *)0x04808180 & 1)) return 0;
    return 1;
}
