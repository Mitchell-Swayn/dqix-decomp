#include "System/Interrupts.h"

#pragma optimize_for_size off

void DMA0InterruptHandler() { OnDMAOrTimerCompletion(0); }
void DMA1InterruptHandler() { OnDMAOrTimerCompletion(1); }
void DMA2InterruptHandler() { OnDMAOrTimerCompletion(2); }
void DMA3InterruptHandler() { OnDMAOrTimerCompletion(3); }
void Timer0OverflowInterruptHandler() { OnDMAOrTimerCompletion(4); }
void Timer1OverflowInterruptHandler() { OnDMAOrTimerCompletion(5); }
void Timer2OverflowInterruptHandler() { OnDMAOrTimerCompletion(6); }
void Timer3OverflowInterruptHandler() { OnDMAOrTimerCompletion(7); }
