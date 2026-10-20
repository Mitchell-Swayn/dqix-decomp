/* Authentic empty cartridge hooks, passed to ARM7_TryLockBus and
 * ARM7_UnlockBus by the NDS bus acquisition/release operations. */
#pragma dont_inline on
// Original: arm7/wram @ 0x037FBC78; symbol: ARM7_MarkNDSBusAcquired.
void ARM7_MarkNDSBusAcquired(void) {}
// Original: arm7/wram @ 0x037FBC7C; symbol: ARM7_MarkNDSBusReleased.
void ARM7_MarkNDSBusReleased(void) {}
