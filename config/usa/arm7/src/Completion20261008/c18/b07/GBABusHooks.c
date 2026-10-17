/* Authentic empty cartridge hooks. The original bodies are each bx lr;
 * they are passed to ARM7_TryLockBus/ARM7_UnlockBus by the GBA bus operations. */
#pragma dont_inline on
// Original: arm7/wram @ 0x037FBC30; symbol: ARM7_MarkGBABusAcquired.
void ARM7_MarkGBABusAcquired(void) {}
// Original: arm7/wram @ 0x037FBC34; symbol: ARM7_MarkGBABusReleased.
void ARM7_MarkGBABusReleased(void) {}
