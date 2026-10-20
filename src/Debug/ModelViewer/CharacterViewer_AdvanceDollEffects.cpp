#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {void CharacterViewer_ReloadDollModelParts(void*);int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);void _ZN8Object3D14AdvanceEffectsEv(void*);extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/ov015 @ 0x0218E4F8; symbol: AdvanceFourObjectsWhenEffectMaskEnabled; size: 0x7c.
// Advances effects on four embedded objects when unrestricted or newly enabled by mask100.
extern "C" void CharacterViewer_AdvanceDollEffects(unsigned char* self) {if(self[0x2c])CharacterViewer_ReloadDollModelParts(self);char* next;int advance=0;char* base=*(char**)(self+0x24);next=base+8;if(self[0x3a]) {if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x100))advance=1;}else advance=1;if(advance){_ZN8Object3D14AdvanceEffectsEv(base);_ZN8Object3D14AdvanceEffectsEv(next+0x400);_ZN8Object3D14AdvanceEffectsEv(base+0x35c);_ZN8Object3D14AdvanceEffectsEv(base+0xac);}}
