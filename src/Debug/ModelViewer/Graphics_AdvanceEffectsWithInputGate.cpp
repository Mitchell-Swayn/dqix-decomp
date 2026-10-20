#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {void CharacterViewer_ReloadPlayerModelParts(unsigned char*);void _ZN8Object3D14AdvanceEffectsEv(void*);int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/ov015 @ 0x0218E498; symbol: func_ov015_0218e498; size: 0x60.
// Reloads changed grouped objects and advances effects under the optional input gate.
extern "C" void Graphics_AdvanceEffectsWithInputGate(unsigned char* self){
 if(self[0x2c])CharacterViewer_ReloadPlayerModelParts(self);
 void* object=*(void**)(self+0x24);
 int advance=0;
 if(self[0x3a]){if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x100))advance=1;}else advance=1;
 if(advance)_ZN8Object3D14AdvanceEffectsEv(object);
}
