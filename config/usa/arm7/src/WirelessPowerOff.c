/* Clear the ARM7 wireless power bit and reset the LED pattern/mode. */
#pragma dont_inline on
extern void ARM7_SetPowerLedPattern(int);
extern void ARM7_SetPowerLedMode(int);
void ARM7_DisableWirelessPower(void)
{
 *(volatile unsigned short*)0x04000304 &= ~2;
 ARM7_SetPowerLedPattern(1);
 ARM7_SetPowerLedMode(1);
}
