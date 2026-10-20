#include <globaldefs.h>
#include <System/Interrupts.h>
ARM
extern "C" int MBi_IsCommSizeValid(unsigned,unsigned,unsigned);
// Original data: arm9/ov027 @ 0x21e33e0; symbol: data_ov027_021e33e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char MBEnd_UnknownRoleZeroInitializedStorage[];
#define P (*(unsigned char**)(MBEnd_UnknownRoleZeroInitializedStorage+8))
// Original: arm9/ov027 @ 0x021DC8D4; symbol: func_ov027_021dc8d4; size: 0x98.
// Sets parent send size and child count with eight-byte child packets when communication is idle.
extern "C" int MB_SetParentCommParam(unsigned short size,unsigned short children)
{
    int irq=DisableIRQInterrupts();
    if(P[0x50d]) { SetIRQInterruptState(irq); return 0; }
    if(!MBi_IsCommSizeValid(size,8,children)) { SetIRQInterruptState(irq); return 0; }
    *(unsigned short*)(P+0x10)=children;
    *(unsigned short*)(P+0x500)=size;
    *(unsigned short*)(P+0x502)=8;
    SetIRQInterruptState(irq);
    return 1;
}
