#include <globaldefs.h>
#include <System/Interrupts.h>
ARM
extern "C" void DisableInterruptsAndHaltForever(void);
extern "C" int MBi_CommEnd(void);
// Original data: arm9/ov027 @ 0x21e33e0; symbol: data_ov027_021e33e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char MBEnd_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov027 @ 0x021DCD20; symbol: func_ov027_021dcd20; size: 0x3C.
// Ends the initialized multiboot session while interrupts are masked.
extern "C" void MB_End(void)
{
    int irq=DisableIRQInterrupts();
    if(!*(unsigned*)(*(unsigned char**)(MBEnd_UnknownRoleZeroInitializedStorage+12)+0x1320))DisableInterruptsAndHaltForever();
    MBi_CommEnd();
    SetIRQInterruptState(irq);
}
