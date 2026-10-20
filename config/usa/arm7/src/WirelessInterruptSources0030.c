/* Accumulate wireless statistics and acknowledge the paired 0x0010/0x0020 sources. */
#pragma dont_inline on
extern void ARM7_AccumulateWirelessStatistics(void);
// Original: arm7/wram @ 0x037F9780; symbol: func_037f9780; size: 0x30.
void ARM7_HandleWirelessSources0030(void)
{
    volatile unsigned short *registerValue;
    ARM7_AccumulateWirelessStatistics();
    registerValue = (volatile unsigned short *)0x048081ac;
    *registerValue = 0xffff;
    *(volatile unsigned short *)0x04808010 = 0x30;
}
