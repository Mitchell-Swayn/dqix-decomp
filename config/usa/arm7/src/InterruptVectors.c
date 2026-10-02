#pragma dont_inline on

/* DMA channels map to response slots 0-3; timer channels map to slots 4-7.
 * Each vector dispatches through the shared callback completion routine. */
extern void ARM7_DispatchInterruptResponse(int);
void ARM7_DMA0InterruptHandler(void) { ARM7_DispatchInterruptResponse(0); }
void ARM7_DMA1InterruptHandler(void) { ARM7_DispatchInterruptResponse(1); }
void ARM7_DMA2InterruptHandler(void) { ARM7_DispatchInterruptResponse(2); }
void ARM7_DMA3InterruptHandler(void) { ARM7_DispatchInterruptResponse(3); }
void ARM7_Timer0OverflowInterruptHandler(void) { ARM7_DispatchInterruptResponse(4); }
void ARM7_Timer1OverflowInterruptHandler(void) { ARM7_DispatchInterruptResponse(5); }
void ARM7_Timer2OverflowInterruptHandler(void) { ARM7_DispatchInterruptResponse(6); }
void ARM7_Timer3OverflowInterruptHandler(void) { ARM7_DispatchInterruptResponse(7); }
