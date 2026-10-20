#include <globaldefs.h>
ARM
// Original data: arm9/ov027 @ 0x21e33ec; symbol: data_ov027_021e33ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char *MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2;
extern "C" int MBi_IsChildAidValid(unsigned);
struct BootableParent { unsigned char pad[0x14e8]; unsigned states[15]; };
// Original: arm9/ov027 @ 0x021D8AEC; symbol: func_ov027_021d8aec; size: 0x54.
// Tests whether a valid child is in the bootable communication state.
extern "C" int MB_CommIsBootable(unsigned child)
{
    if(MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2 && MBi_IsChildAidValid(child) && ((BootableParent*)MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2)->states[child-1]==7)return 1;
    return 0;
}
