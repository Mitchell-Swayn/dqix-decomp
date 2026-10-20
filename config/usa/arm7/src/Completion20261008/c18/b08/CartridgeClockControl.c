#pragma dont_inline on
/* Preserve the other EXMEMCNT fields while replacing the GBA clock field. */
// Original: arm7/wram @ 0x03807564; symbol: ARM7_SetCartridgeClockControl.
void ARM7_SetCartridgeClockControl(int value)
{
 *(volatile unsigned short*)0x04000204=(*(volatile unsigned short*)0x04000204&~16)|(value<<4);
}
