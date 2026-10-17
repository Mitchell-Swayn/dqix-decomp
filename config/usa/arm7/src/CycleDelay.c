/* The native wrapper divides signed cycle counts by four before calling
 * the Thumb delay routine. The BIOS-facing target remains binary fallback. */
extern void ARM7_BiosDelay(int);
// Original: arm7/wram @ 0x037FE3C8; symbol: ARM7_WaitCycles.
void ARM7_WaitCycles(int cycles) { ARM7_BiosDelay(cycles/4); }
