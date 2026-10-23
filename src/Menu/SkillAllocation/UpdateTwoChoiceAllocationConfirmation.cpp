#include <globaldefs.h>
ARM
struct State;
extern "C" void InitializeTwoChoiceConfirmationLayout(unsigned char*);
extern "C" void Window_SelectCanvasById(unsigned char*,unsigned);
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
extern "C" int Selection_ReadEnabledIndexFromControl(void*);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
extern "C" void Window_PopCanvasesAndResetSelection(State*,int);
extern "C" void Input_SuppressKeyRepeatUntilRelease(void*);
extern "C" void SkillAllocation_SetTextRecordTransitionFlag(void*,unsigned,int);
extern "C" void RefreshHeadingAndUploadFontTiles(char*);
extern "C" int TestSelectedRecordReadyAndByteFlagBitOne(char*,int);
extern "C" void Resource_ClearAndInitializeOwnerBufferFromRecordThree(void*);
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
#define W(o) (*(int*)(p+(o)))
#define RESET() Window_PopCanvasesAndResetSelection((State*)(p+0x38),0)
#define MODE(m) Window_SelectCanvasById(p+0x38,m)
#define SOUND() SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0)
#define READY() ((int(*)(char*,int))TestSelectedRecordReadyAndByteFlagBitOne)((char*)p+0x38,20)
// Original: arm9/ov013 @ 0x0218683C; symbol: func_ov013_0218683c; size: 0x398.
// Handles two-choice confirmation, cancellation, and layout refresh for allocation states.
extern "C" void UpdateTwoChoiceAllocationConfirmation(unsigned char* p){
 p[0x6bc]|=1;int dirty=0;p[0x63a]=0;
 if(p[0x63e]==0){if(p[0x63c]==4)W(0x660)=1;else W(0x660)=0;InitializeTwoChoiceConfirmationLayout(p);p[0x63e]++;return;}
 if(p[0x63e]!=1)return;
 MODE(3);p[0x63b]=0;
 if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0xc0)){W(0x660)=!W(0x660);dirty=1;}
 if(W(0x648)==2){W(0x660)=(signed char)Selection_ReadEnabledIndexFromControl(p+0x38);dirty=1;}
 if(p[0x63d]==p[0x63c]){
 if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x601)){
 SOUND();
 if(p[0x63c]==4){
 if(W(0x660)==0){p[0x63c]=5;Window_PopCanvasesAndResetSelection((State*)(p+0x38),1);p[0x664]=0;}
 else{p[0x63c]=1;Input_SuppressKeyRepeatUntilRelease(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage);p[0x664]=0;MODE(3);RESET();MODE(2);RESET();p[0x639]=0;p[0x6bc]&=~1;SkillAllocation_SetTextRecordTransitionFlag(p,0,0);RefreshHeadingAndUploadFontTiles((char*)p);}
 }else{
 if(W(0x660)==0){p[0x664]=1;p[0x63c]=5;Window_PopCanvasesAndResetSelection((State*)(p+0x38),1);}
 else{MODE(3);RESET();MODE(2);RESET();p[0x639]=0;p[0x63c]=1;Input_SuppressKeyRepeatUntilRelease(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage);p[0x6bc]&=~1;SkillAllocation_SetTextRecordTransitionFlag(p,0,0);RefreshHeadingAndUploadFontTiles((char*)p);}
 }
 p[0x63e]=0;
 }else if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2)||(W(0x660)==1&&READY())){
 if(!Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2))SOUND();
 MODE(3);RESET();MODE(2);RESET();p[0x639]=0;p[0x63c]=1;Input_SuppressKeyRepeatUntilRelease(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage);p[0x63e]=0;p[0x6bc]&=~1;SkillAllocation_SetTextRecordTransitionFlag(p,0,0);RefreshHeadingAndUploadFontTiles((char*)p);
 }else if(W(0x660)==0&&READY()){
 SOUND();
 if(p[0x63c]==4){p[0x63c]=5;Window_PopCanvasesAndResetSelection((State*)(p+0x38),1);p[0x664]=0;}
 else{p[0x664]=1;p[0x63c]=5;Window_PopCanvasesAndResetSelection((State*)(p+0x38),1);p[0x63e]=0;}
 }
 }
 if(dirty)Resource_ClearAndInitializeOwnerBufferFromRecordThree(p);
}
