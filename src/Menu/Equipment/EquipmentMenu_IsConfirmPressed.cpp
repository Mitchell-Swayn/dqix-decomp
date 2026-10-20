// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" { extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[]; int Input_IsKeyMaskNewlyPressed(void*,unsigned); }
// Original: arm9/ov005 @ 0x02157190; symbol: func_ov005_02157190; size: 0x40.
extern "C" int EquipmentMenu_IsConfirmPressed(void* unused) { int result=0; if(!Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x30)) { if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x401)) result=1; } return result; }
