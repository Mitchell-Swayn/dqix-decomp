#pragma dont_inline on
extern void ARM7_SetCartridgeWaitControl(int);
extern void ARM7_SetCartridgeClockControl(int);
/* Snapshot two EXMEMCNT fields before applying the probe settings. */
// Original: arm7/wram @ 0x03807504; symbol: ARM7_SaveCartridgeBusControl.
void ARM7_SaveCartridgeBusControl(int *saved)
{
 saved[0]=(*(volatile unsigned short*)0x04000204&12)>>2;
 saved[1]=(*(volatile unsigned short*)0x04000204&16)>>4;
 ARM7_SetCartridgeWaitControl(3);
 ARM7_SetCartridgeClockControl(0);
}
