#include <globaldefs.h>
ARM
extern "C" int Network_SetInterruptProtectedPeerStatus(int,int);
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" void _Z20SetIRQInterruptStatei(int);
// Original data: arm9/ov031 @ 0x2290d14; symbol: data_ov031_02290d14.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short* MultibootGetParentState_UnknownRoleZeroInitializedStorage;
extern "C" void Resource_ResetPendingAndStatusFields(int);
// Original: arm9/ov031 @ 0x02238910; symbol: Network_ClearPeerBitFromSixSharedMasks; size: 0xa0.
// Clears peer-index bit in six shared masks atomically after peer reset succeeds.
extern "C" void Network_ClearPeerBitFromSixSharedMasks(int index) {
 if(Network_SetInterruptProtectedPeerStatus(index,1))return;unsigned short mask=~(1<<index);int irq=_Z20DisableIRQInterruptsv();
 MultibootGetParentState_UnknownRoleZeroInitializedStorage[1]&=mask;MultibootGetParentState_UnknownRoleZeroInitializedStorage[2]&=mask;MultibootGetParentState_UnknownRoleZeroInitializedStorage[3]&=mask;MultibootGetParentState_UnknownRoleZeroInitializedStorage[4]&=mask;MultibootGetParentState_UnknownRoleZeroInitializedStorage[5]&=mask;MultibootGetParentState_UnknownRoleZeroInitializedStorage[6]&=mask;
 _Z20SetIRQInterruptStatei(irq);Resource_ResetPendingAndStatusFields(index);
}
