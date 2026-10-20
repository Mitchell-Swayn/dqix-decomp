/* Read-modify-write the 16-bit GPIO control register with caller masks. */
#pragma dont_inline on
// Original: arm7/wram @ 0x037FEC18; symbol: ARM7_UpdateGPIOControl.
void ARM7_UpdateGPIOControl(unsigned int clearMask,unsigned int setMask)
{
 volatile unsigned short *control=(volatile unsigned short*)0x04000134;
 *control=(~clearMask & *control)|setMask;
}
