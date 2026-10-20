#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char* p,int a,void* b);
extern "C" void TextCanvas_HideDisplayPart(unsigned char* p,int i);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(char* self,int index);
extern "C" void KeyRepeater_Reset(unsigned char* p);
extern "C" void Window_CreateOptionLayoutAndResetSelection(unsigned char* p,int value);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov003 @ 0x02176468; symbol: func_ov003_02176468; size: 0x8C.
extern "C" void Graphics_ResetDisplaySelectionAndLinkedOwner(unsigned char* p) {
*(short*)(p+0xffe)=1;
*(short*)(p+0x1000)=*(short*)(p+0x1002)=2;
*(short*)(*(unsigned char**)(p+0x89c)+0x36)=*(short*)(p+0x1002);
TextCanvas_CreateAndConfigureDisplayPart(*(char**)(p+0x89c),*(short*)(p+0xffe));
KeyRepeater_Reset(p+0x88c);
*(int*)(p+0xff8)=0;
SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,5,0);
if(*(void**)p){TextCanvas_HideDisplayPart(*(unsigned char**)(p+0x89c),*(short*)(p+0xffe));Window_CreateOptionLayoutAndResetSelection(*(unsigned char**)p,-1);}
}
