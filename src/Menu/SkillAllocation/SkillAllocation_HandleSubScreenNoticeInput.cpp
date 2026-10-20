#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" int Input_IsKeyMaskNewlyPressed(void*,unsigned);
extern "C" int TouchInput_IsNewPress(void*);
extern "C" void Input_SuppressKeyRepeatUntilRelease(void*);
extern "C" void Window_SelectCanvasById(void*,unsigned);
extern "C" void Window_PopCanvasesAndResetSelection(void*,int);
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
// Original: arm9/ov013 @ 0x0218678C; symbol: ResetMatchingSelectionStateForNewInput; size: 0xb0.
// Resets matching selection state for new input613 or configuration predicate, clearing transient flags.
extern "C" void SkillAllocation_HandleSubScreenNoticeInput(char* p){
 B(p,0x6bc)&=~1;B(p,0x63a)=0;if(B(p,0x63d)!=B(p,0x63c))return;
 if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x613)||TouchInput_IsNewPress(Main_UnknownRoleZeroInitializedStorage_Variant4)){
 B(p,0x63c)=1;Input_SuppressKeyRepeatUntilRelease(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage);Window_SelectCanvasById(p+0x38,2);Window_PopCanvasesAndResetSelection(p+0x38,0);B(p,0x639)=0;B(p,0x6bc)&=~1;SkillAllocation_SetTextRecordTransitionFlag(p,0,0);RefreshHeadingAndUploadFontTiles(p);}
}
