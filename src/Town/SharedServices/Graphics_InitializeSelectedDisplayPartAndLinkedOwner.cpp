#include <globaldefs.h>
ARM
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
extern "C" void TextCanvas_HideDisplayPart(unsigned char*,int);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
extern "C" void KeyRepeater_Reset(unsigned char*);
extern "C" void Window_CreateOptionLayoutAndResetSelection(unsigned char*,int);
extern "C" void Window_SetInitialOption(char*,int);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov003 @ 0x02155580; symbol: func_ov003_02155580; size: 0x98.
extern "C" void Graphics_InitializeSelectedDisplayPartAndLinkedOwner(unsigned char* self,int value) {
 *(short*)(self+0x1e6)=1;
 *(short*)(self+0x1e8)=*(short*)(self+0x1ea)=6;
 *(short*)(*(char**)(self+0x18)+0x36)=*(short*)(self+0x1ea);
 TextCanvas_CreateAndConfigureDisplayPart(*(char**)(self+0x18),*(short*)(self+0x1e6));
 KeyRepeater_Reset(self+0x80);
 *(int*)(self+8)=0;
 SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,5,0);
 if(*(void**)(self+0x1c)) {
  TextCanvas_HideDisplayPart(*(unsigned char**)(self+0x18),*(short*)(self+0x1e6));
  Window_SetInitialOption(*(char**)(self+0x1c),(signed char)value);
  Window_CreateOptionLayoutAndResetSelection(*(unsigned char**)(self+0x1c),-1);
 }
}
