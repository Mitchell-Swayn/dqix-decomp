#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv(void);
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" int MBi_IsChildAidValid(unsigned);
// Original data: arm9/ov027 @ 0x21e33ec; symbol: data_ov027_021e33ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov027 @ 0x021D8B40; symbol: func_ov027_021d8b40; size: 0xE0.
// Updates a peer's status only when its current parent state matches the requested transition.
extern "C" int Network_SetInterruptProtectedPeerStatus(unsigned peer,unsigned requestedState)
{
    unsigned newStatus,requiredState;
    int irq;
    irq=_Z20DisableIRQInterruptsv();
    switch(requestedState) {
    case 0: requiredState=10; newStatus=4; break;
    case 1: requiredState=10; newStatus=3; break;
    case 2: requiredState=14; newStatus=2; break;
    case 3: requiredState=7; newStatus=5; break;
    default: _Z20SetIRQInterruptStatei(irq); return 0;
    }
    if(MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2[0] && MBi_IsChildAidValid(peer)) {
        unsigned slot=peer-1;
        unsigned *parent=(unsigned*)MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2[0];
        if(*(unsigned*)((char*)parent+0x14e8+slot*4)==requiredState) {
            *(unsigned short*)((char*)parent+0x1754+slot*2)=newStatus;
            _Z20SetIRQInterruptStatei(irq);
            return 1;
        }
    }
    _Z20SetIRQInterruptStatei(irq);
    return 0;
}
