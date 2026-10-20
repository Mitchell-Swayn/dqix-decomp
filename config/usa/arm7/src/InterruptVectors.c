#pragma dont_inline on

/* DMA channels map to response slots 0-3; timer channels map to slots 4-7.
 * Each vector dispatches through the shared callback completion routine. */
extern void ARM7_DispatchInterruptResponse(int);
// Original: arm7/wram @ 0x037FB6FC; symbol: ARM7_DMA0InterruptHandler.
void ARM7_DMA0InterruptHandler(void) { ARM7_DispatchInterruptResponse(0); }
// Original: arm7/wram @ 0x037FB70C; symbol: ARM7_DMA1InterruptHandler.
void ARM7_DMA1InterruptHandler(void) { ARM7_DispatchInterruptResponse(1); }
// Original: arm7/wram @ 0x037FB71C; symbol: ARM7_DMA2InterruptHandler.
void ARM7_DMA2InterruptHandler(void) { ARM7_DispatchInterruptResponse(2); }
// Original: arm7/wram @ 0x037FB72C; symbol: ARM7_DMA3InterruptHandler.
void ARM7_DMA3InterruptHandler(void) { ARM7_DispatchInterruptResponse(3); }
// Original: arm7/wram @ 0x037FB73C; symbol: ARM7_Timer0OverflowInterruptHandler.
void ARM7_Timer0OverflowInterruptHandler(void) { ARM7_DispatchInterruptResponse(4); }
// Original: arm7/wram @ 0x037FB74C; symbol: ARM7_Timer1OverflowInterruptHandler.
void ARM7_Timer1OverflowInterruptHandler(void) { ARM7_DispatchInterruptResponse(5); }
// Original: arm7/wram @ 0x037FB75C; symbol: ARM7_Timer2OverflowInterruptHandler.
void ARM7_Timer2OverflowInterruptHandler(void) { ARM7_DispatchInterruptResponse(6); }
// Original: arm7/wram @ 0x037FB76C; symbol: ARM7_Timer3OverflowInterruptHandler.
void ARM7_Timer3OverflowInterruptHandler(void) { ARM7_DispatchInterruptResponse(7); }
