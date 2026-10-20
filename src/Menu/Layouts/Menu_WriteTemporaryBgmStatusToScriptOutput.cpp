#include <globaldefs.h>
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned Main_UnknownRoleZeroInitializedStorage_Variant2[];
extern "C" unsigned Bgm_IsTemporarySequencePendingOrPlaying(unsigned*);
extern "C" void Menu_WriteScriptIntegerReference(void*, unsigned);
// Original: arm9/ov011 @ 0x02188438; symbol: func_ov011_02188438; size: 0x28.
extern "C" unsigned Menu_WriteTemporaryBgmStatusToScriptOutput(void* self) {
 unsigned value = Bgm_IsTemporarySequencePendingOrPlaying(Main_UnknownRoleZeroInitializedStorage_Variant2);
 Menu_WriteScriptIntegerReference(self,value);
 return 1;
}
