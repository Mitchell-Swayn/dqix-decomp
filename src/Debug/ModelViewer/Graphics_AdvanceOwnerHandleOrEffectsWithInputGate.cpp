#include <globaldefs.h>
ARM
struct HandleOwner;
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);void ResourceTracks_AdvanceBoundPlayback(HandleOwner*);void _ZN8Object3D14AdvanceEffectsEv(void*);extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/ov015 @ 0x0218E60C; symbol: func_ov015_0218e60c; size: 0x64.
// Advances an optional owner handle or object effects under the input gate.
extern "C" void Graphics_AdvanceOwnerHandleOrEffectsWithInputGate(unsigned char* self){
 int advance=0;
 if(self[0x3a]){if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x100))advance=1;}else advance=1;
 if(advance){unsigned char* owner=*(unsigned char**)(self+0x28);if(*(void**)(owner+0xc))ResourceTracks_AdvanceBoundPlayback((HandleOwner*)owner);else _ZN8Object3D14AdvanceEffectsEv(*(void**)(self+0x24));}
}
