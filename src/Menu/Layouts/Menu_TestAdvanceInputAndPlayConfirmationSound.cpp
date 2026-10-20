#include <globaldefs.h>
struct Flags { char prefix[0x55]; unsigned char enabled; };
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Flags Main_UnknownRoleZeroInitializedStorage_Variant4;
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned Main_UnknownRoleZeroInitializedStorage[];
extern "C" int Input_IsKeyMaskNewlyPressed(void*, unsigned);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(void*, unsigned, unsigned);
extern "C" void Menu_WriteScriptIntegerReference(void*, unsigned);
// Original: arm9/ov011 @ 0x021884D0; symbol: func_ov011_021884d0; size: 0x64.
extern "C" unsigned Menu_TestAdvanceInputAndPlayConfirmationSound(void* self) {
 unsigned value=0;
 if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x7f3) || Main_UnknownRoleZeroInitializedStorage_Variant4.enabled) {
  SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
  value=1;
 }
 Menu_WriteScriptIntegerReference(self,value);
 return 1;
}
