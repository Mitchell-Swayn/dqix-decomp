#include "System/Interrupts.h"

#pragma optimize_for_size off

// Original: arm9/main @ 0x020C6A54; symbol: _Z20DMA0InterruptHandlerv; size: 0x10.
void DMA0InterruptHandler() { OnDMAOrTimerCompletion(0); }
// Original: arm9/main @ 0x020C6A64; symbol: _Z20DMA1InterruptHandlerv; size: 0x10.
void DMA1InterruptHandler() { OnDMAOrTimerCompletion(1); }
// Original: arm9/main @ 0x020C6A74; symbol: _Z20DMA2InterruptHandlerv; size: 0x10.
void DMA2InterruptHandler() { OnDMAOrTimerCompletion(2); }
// Original: arm9/main @ 0x020C6A84; symbol: _Z20DMA3InterruptHandlerv; size: 0x10.
void DMA3InterruptHandler() { OnDMAOrTimerCompletion(3); }
// Original: arm9/main @ 0x020C6A94; symbol: _Z30Timer0OverflowInterruptHandlerv; size: 0x10.
void Timer0OverflowInterruptHandler() { OnDMAOrTimerCompletion(4); }
// Original: arm9/main @ 0x020C6AA4; symbol: _Z30Timer1OverflowInterruptHandlerv; size: 0x10.
void Timer1OverflowInterruptHandler() { OnDMAOrTimerCompletion(5); }
// Original: arm9/main @ 0x020C6AB4; symbol: _Z30Timer2OverflowInterruptHandlerv; size: 0x10.
void Timer2OverflowInterruptHandler() { OnDMAOrTimerCompletion(6); }
// Original: arm9/main @ 0x020C6AC4; symbol: _Z30Timer3OverflowInterruptHandlerv; size: 0x10.
void Timer3OverflowInterruptHandler() { OnDMAOrTimerCompletion(7); }
