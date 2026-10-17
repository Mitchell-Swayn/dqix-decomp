/* Set the GPIO mode bits, preserving the original 16-bit input narrowing. */
#pragma dont_inline on
extern void ARM7_UpdateGPIOControl(unsigned int,unsigned int);
// Original: arm7/wram @ 0x037FEC38; symbol: ARM7_SetGPIOControlMode.
void ARM7_SetGPIOControlMode(unsigned int mode)
{
 ARM7_UpdateGPIOControl(0xc000,(unsigned short)mode);
}
