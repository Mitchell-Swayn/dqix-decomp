#pragma dont_inline on
/* Preserve the other EXMEMCNT fields while replacing the GBA wait field. */
// Original: arm7/wram @ 0x03807548; symbol: ARM7_SetCartridgeWaitControl.
void ARM7_SetCartridgeWaitControl(int value)
{
 *(volatile unsigned short*)0x04000204=(*(volatile unsigned short*)0x04000204&~12)|(value<<2);
}
