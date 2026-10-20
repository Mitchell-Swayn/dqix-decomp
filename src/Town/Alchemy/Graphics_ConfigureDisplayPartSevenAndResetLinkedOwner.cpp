#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
extern "C" void TextCanvas_HideDisplayPart(unsigned char*,int);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
extern "C" void KeyRepeater_Reset(unsigned char*);
extern "C" void Window_CreateOptionLayoutAndResetSelection(unsigned char*,int);
extern "C" void WindowControl_SetInsideMaskWithEffect(void*,int,int);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov006 @ 0x02159DB0; symbol: func_ov006_02159db0; size: 0xA0.
extern "C" void Graphics_ConfigureDisplayPartSevenAndResetLinkedOwner(unsigned char* p){
 SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,5,0);
 short part=7;short value=34;
 *(short*)(p+0x36e)=part;
 *(short*)(p+0x35e)=*(short*)(p+0x36c)=value;
 *(short*)(*(unsigned char**)(p+0x14)+0x36)=*(short*)(p+0x36c);
 TextCanvas_CreateAndConfigureDisplayPart(*(char**)(p+0x14),*(short*)(p+0x36e));
 KeyRepeater_Reset(p+0x9c);
 *(int*)(p+0x44)=0;
 if(*(void**)(p+0x18)){
 TextCanvas_HideDisplayPart(*(unsigned char**)(p+0x14),*(short*)(p+0x36e));
 Window_CreateOptionLayoutAndResetSelection(*(unsigned char**)(p+0x18),-1);
 WindowControl_SetInsideMaskWithEffect(*(unsigned char**)(*(unsigned char**)(p+0x18)+0x10)+0x28,24,1);
 }
}
