// DTCM initialized storage: the interrupt dispatch table, not the full 16 KiB
// memory-mapped DTCM view declared by System/DTCM.h. Slots 22 and 23 are
// reserved; DMA and timer slots initially dispatch their callback wrappers.
typedef void (*InterruptHandler)();
void EmptyInterruptHandler();
void DMA0InterruptHandler();
void DMA1InterruptHandler();
void DMA2InterruptHandler();
void DMA3InterruptHandler();
void Timer0OverflowInterruptHandler();
void Timer1OverflowInterruptHandler();
void Timer2OverflowInterruptHandler();
void Timer3OverflowInterruptHandler();

struct InitialInterruptTable { InterruptHandler handlers[24]; };
typedef char InitialInterruptTableSizeCheck[sizeof(InitialInterruptTable) == 96 ? 1 : -1];

InitialInterruptTable data_027e0000 = {{
    EmptyInterruptHandler, EmptyInterruptHandler, EmptyInterruptHandler,
    Timer0OverflowInterruptHandler, Timer1OverflowInterruptHandler,
    Timer2OverflowInterruptHandler, Timer3OverflowInterruptHandler,
    EmptyInterruptHandler,
    DMA0InterruptHandler, DMA1InterruptHandler, DMA2InterruptHandler, DMA3InterruptHandler,
    EmptyInterruptHandler, EmptyInterruptHandler, EmptyInterruptHandler,
    EmptyInterruptHandler, EmptyInterruptHandler, EmptyInterruptHandler,
    EmptyInterruptHandler, EmptyInterruptHandler, EmptyInterruptHandler,
    EmptyInterruptHandler, 0, 0
}};
