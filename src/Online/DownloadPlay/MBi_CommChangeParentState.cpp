#include <globaldefs.h>
ARM
// Original data: arm9/ov027 @ 0x21e33ec; symbol: data_ov027_021e33ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char *MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2;
extern "C" int MBi_IsChildAidValid(unsigned value);
extern "C" void MBi_CommChangeParentStateCallbackOnly(unsigned child, unsigned state, void *payload);
struct ParentStateTable {
    unsigned char pad[0x14e8];
    unsigned state[15];
};
// Original: arm9/ov027 @ 0x021D8C20; symbol: func_ov027_021d8c20; size: 0x4C.
// Updates a valid child's parent-state word, then invokes the parent-state callback.
extern "C" void MBi_CommChangeParentState(unsigned child, unsigned state, void *payload)
{
    if(MBi_IsChildAidValid(child)) {
        ((ParentStateTable*)MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2)->state[child-1]=state;
    }
    MBi_CommChangeParentStateCallbackOnly(child,state,payload);
}
