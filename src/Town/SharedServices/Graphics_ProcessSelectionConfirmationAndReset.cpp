#include <globaldefs.h>
ARM
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
extern "C" void TextCanvas_ResetDisplayPartByKey(unsigned char*,int);
extern "C" void KeyRepeater_Reset(unsigned char*);
extern "C" void Window_HideAndResetOptionSelection(void**);
extern "C" int Shop_TestSelectionConfirmation(char*);
extern "C" int Shop_TestSelectionCancellation(unsigned char*);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov003 @ 0x021764F4; symbol: func_ov003_021764f4; size: 0xC0.
extern "C" int Graphics_ProcessSelectionConfirmationAndReset(unsigned char* p){
 *(void**)(p+0xff8)=p+0x1002;
 int result=0;
 if(Shop_TestSelectionConfirmation((char*)p) || Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x200)){
 SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
 result=-1;
 if(*(short*)(p+0x1002)==2)result=1;
 }else if(Shop_TestSelectionCancellation(p))result=-1;
 if(result){
 TextCanvas_ResetDisplayPartByKey(*(unsigned char**)(p+0x89c),*(short*)(p+0xffe));
 KeyRepeater_Reset(p+0x88c);
 *(void**)(p+0xff8)=0;
 }
 if(*(void**)p && result)Window_HideAndResetOptionSelection(*(void***)p);
 return result;
}
