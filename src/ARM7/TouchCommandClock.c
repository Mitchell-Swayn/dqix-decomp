/* Transmit a zero byte and wait for the touch command SPI port to idle. */
#pragma dont_inline on
void ARM7_ClockTouchCommandByte(void)
{
 *(volatile unsigned short*)0x040001c2=0;
 while(*(volatile unsigned short*)0x040001c0&0x80) {}
}
