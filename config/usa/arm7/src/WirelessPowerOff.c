/* Clear the ARM7 wireless power bit and invoke the two opaque shutdown hooks. */
#pragma dont_inline on
extern void ARM7_WirelessPowerOffHook1(int);
extern void ARM7_WirelessPowerOffHook2(int);
void ARM7_DisableWirelessPower(void)
{
 *(volatile unsigned short*)0x04000304 &= ~2;
 ARM7_WirelessPowerOffHook1(1);
 ARM7_WirelessPowerOffHook2(1);
}
