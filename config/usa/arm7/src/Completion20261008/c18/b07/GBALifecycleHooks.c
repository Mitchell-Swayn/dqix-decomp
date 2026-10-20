/* Authentic empty GBA bus lifecycle hooks. Acquire/release calls use the
 * first two; bus initialization calls the third. Every original body is bx lr. */
#pragma dont_inline on
// Original: arm7/wram @ 0x03803F1C; symbol: ARM7_BeforeReleaseGBABus.
void ARM7_BeforeReleaseGBABus(void) {}
// Original: arm7/wram @ 0x03803F20; symbol: ARM7_AfterAcquireGBABus.
void ARM7_AfterAcquireGBABus(void) {}
// Original: arm7/wram @ 0x03803F24; symbol: ARM7_InitializeBusLockHardware.
void ARM7_InitializeBusLockHardware(void) {}
