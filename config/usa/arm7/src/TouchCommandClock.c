/* Transmit a zero byte and wait for the touch command SPI port to idle. */
#pragma dont_inline on
// Original: arm7/wram @ 0x038056AC; symbol: ARM7_ClockTouchCommandByte.
void ARM7_ClockTouchCommandByte(void)
{
 *(volatile unsigned short*)0x040001c2=0;
 while(*(volatile unsigned short*)0x040001c0&0x80) {}
}
