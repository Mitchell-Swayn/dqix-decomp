#include <globaldefs.h>
#include <System/Interrupts.h>
#include <System/Memory.h>
ARM
extern "C" int MBi_IsChildAidValid(unsigned);
// Original data: arm9/ov027 @ 0x21e33ec; symbol: data_ov027_021e33ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char *MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2;
struct UserContext { unsigned char pad[0x1340]; unsigned char users[15][22]; unsigned char gap[0x1772-0x148a]; unsigned char copy[22]; };
// Original: arm9/ov027 @ 0x021D8A68; symbol: func_ov027_021d8a68; size: 0x84.
// Copies the selected child user record under the IRQ mask to the shared result buffer.
extern "C" void *MB_CommGetChildUser(unsigned child)
{
    int irq=DisableIRQInterrupts();
    if(MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2 && MBi_IsChildAidValid(child)) {
        MI_CpuCopy8(((UserContext*)MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2)->users[child-1],((UserContext*)MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2)->copy,22);
        SetIRQInterruptState(irq);
        return ((UserContext*)MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2)->copy;
    }
    SetIRQInterruptState(irq);
    return 0;
}
