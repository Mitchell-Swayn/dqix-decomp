#include <globaldefs.h>
#include <System/Interrupts.h>
ARM
struct QueueTask;
extern "C" int MBi_IsTaskAvailable();
extern "C" void MBi_SetTask(QueueTask*,void(*)(QueueTask*),void(*)(QueueTask*),unsigned);
// Original data: arm9/ov027 @ 0x21e3420; symbol: data_ov027_021e3420.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char *MBiSetTask_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov027 @ 0x021DD55C; symbol: func_ov027_021dd55c; size: 0x48.
// Queues the terminal task with an optional completion callback under the IRQ mask.
extern "C" void MBi_EndTaskThread(void (*complete)(QueueTask*))
{
    int irq=DisableIRQInterrupts();
    if(MBi_IsTaskAvailable())MBi_SetTask((QueueTask*)(MBiSetTask_UnknownRoleZeroInitializedStorage+0xc4),0,complete,0);
    SetIRQInterruptState(irq);
}
