#include <globaldefs.h>
// Original data: arm9/ov028 @ 0x21d9ae0; symbol: data_ov028_021d9ae0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov028.md.
// Original data: arm9/ov028 @ 0x21d9b14; symbol: data_ov028_021d9b14.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 176 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov028.md.
extern "C" { extern unsigned char StaffRollStopAndRestoreDisplay_UnknownRoleZeroInitializedStorage_Variant2[],SinitOv028021D9A54_UnknownRoleZeroInitializedStorage[];void* StaffRoll_ConstructState(void*);void* StaffRoll_DestructState(void*);void __register_global_object(void*,void (*)(void*,int),void*); }
#pragma define_section init ".init" RX
// Original: arm9/ov028 @ 0x021D9A54; symbol: __sinit_ov028_021d9a54; size: 0x2C.
extern "C" __declspec(section "init") void __sinit_ov028_021d9a54(){StaffRoll_ConstructState(StaffRollStopAndRestoreDisplay_UnknownRoleZeroInitializedStorage_Variant2);__register_global_object(StaffRollStopAndRestoreDisplay_UnknownRoleZeroInitializedStorage_Variant2,(void(*)(void*,int))StaffRoll_DestructState,SinitOv028021D9A54_UnknownRoleZeroInitializedStorage);}
