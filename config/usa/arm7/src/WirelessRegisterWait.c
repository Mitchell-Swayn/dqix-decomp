/* Poll wireless indexed-register busy bit0 for at most0x2800 reads. */
#pragma dont_inline on
// Original: arm7/wram @ 0x037FB454; symbol: func_037fb454; size: 0x34.
int ARM7_WaitWirelessIndexedRegisterReady(void)
{
    unsigned int count = 0;
    for (; count < 0x2800; count++)
        if (!(*(volatile unsigned short *)0x0480815e & 1)) return 0;
    return 1;
}
