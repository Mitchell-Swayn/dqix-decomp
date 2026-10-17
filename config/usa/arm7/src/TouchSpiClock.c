/* Clock one zero byte through SPI and wait for the transaction to finish. */
#pragma dont_inline on
// Original: arm7/wram @ 0x03805050; symbol: ARM7_ClockTouchSpiByte.
void ARM7_ClockTouchSpiByte(void)
{
 *(volatile unsigned short*)0x040001c2=0;
 while(*(volatile unsigned short*)0x040001c0&0x80) {}
}
