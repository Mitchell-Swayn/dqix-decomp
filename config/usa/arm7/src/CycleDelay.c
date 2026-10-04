/* The native wrapper divides signed cycle counts by four before calling
 * the Thumb delay routine. The BIOS-facing target remains binary fallback. */
extern void ARM7_BiosDelay(int);
void ARM7_WaitCycles(int cycles) { ARM7_BiosDelay(cycles/4); }
