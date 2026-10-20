#include <globaldefs.h>
ARM
extern "C" char* TextContext_GetSharedInstance();
extern "C" int Input_IsKeyMaskNewlyPressed(void*,unsigned);
extern "C" int TouchInput_IsNewPress(void*);
extern "C" void Input_SuppressKeyRepeatUntilRelease(void*);
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);
extern "C" void SkillAllocation_SetTextRecordTransitionFlag(void*,unsigned,int);
extern "C" void RefreshHeadingAndUploadFontTiles(void*);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[],Main_UnknownRoleZeroInitializedStorage_Variant4[];
// Original: arm9/ov013 @ 0x021864F0; symbol: ResetSelectionForNewInputOrConfiguration; size: 0xa0.
// Clears transient flag and resets selection when new input mask613 or configuration predicate is true.
extern "C" void SkillAllocation_HandleMainScreenNoticeInput(unsigned char* p){
 p[0x6bc]&=~1;if(p[0x63f])p[0x639]=1;
 char* owner=TextContext_GetSharedInstance();owner[0x19be]=1;
 if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x613)||TouchInput_IsNewPress(Main_UnknownRoleZeroInitializedStorage_Variant4)){
 p[0x63c]=1;Input_SuppressKeyRepeatUntilRelease(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage);TextWindow_ResetGlyphBuffersAndFrameContexts(owner);p[0x639]=0;SkillAllocation_SetTextRecordTransitionFlag(p,0,0);RefreshHeadingAndUploadFontTiles(p);}
}
