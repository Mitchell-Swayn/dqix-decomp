#include <globaldefs.h>
#include <System/Interrupts.h>
extern "C" char data_ov031_0224e540[];
// Stores a word at offset 0x28 while preserving the IRQ state.
// Original: arm9/ov031 @ 0x0220F0E4; symbol: func_ov031_0220f0e4; size: 0x20.
extern "C" ARM void SetGlobalWordAtOffset28(unsigned int value)
{
    unsigned int irq = DisableIRQInterrupts();
    *(unsigned int*)(data_ov031_0224e540 + 0x28) = value;
    SetIRQInterruptState(irq);
}
