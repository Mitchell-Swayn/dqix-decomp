#include <globaldefs.h>
#include <System/Interrupts.h>
// Original data: arm9/ov031 @ 0x224e540; symbol: data_ov031_0224e540.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char SystemHandleType12Message_UnknownRoleZeroInitializedStorage[];
// Stores a word at offset 0x28 while preserving the IRQ state.
// Original: arm9/ov031 @ 0x0220F0E4; symbol: func_ov031_0220f0e4; size: 0x20.
extern "C" ARM void Network_SetDcfReceiveCallback(unsigned int value)
{
    unsigned int irq = DisableIRQInterrupts();
    *(unsigned int*)(SystemHandleType12Message_UnknownRoleZeroInitializedStorage + 0x28) = value;
    SetIRQInterruptState(irq);
}
