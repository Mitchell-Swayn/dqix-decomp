#include <globaldefs.h>
ARM
struct State;struct Owner;
extern "C" void Window_SelectCanvasById(unsigned char*,unsigned);
extern "C" int Selection_ReadEnabledIndexFromControl(void*);
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
extern "C" void Window_SetEnabledSelectionIndices(unsigned char*,int);
extern "C" int Window_ClassifyTouchAgainstSelectedCanvas(void*);
extern "C" int Input_PollKeyRepeatCountdown(State*,unsigned);
extern "C" int SkillAllocation_HitTestAdjustmentTouchRegion(Owner*,int);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
extern "C" void Window_PopCanvasesAndResetSelection(State*,int);
extern "C" void SkillAllocation_InitializeSubScreenPromptPanel(unsigned char*);
extern "C" void SkillAllocation_ShowMainScreenPrompt(char*);
extern "C" void SkillAllocation_SetTextRecordTransitionFlag(void*,unsigned,int);
extern "C" void Graphics_FormatFiveRowSelectionTextAndRefreshOwner(void*);
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
#define WI(o,i) (*(int*)(p+(i)*4+(o)))
#define W(o) (*(int*)(p+(o)))
#define Sound(a) SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,a,0)
// Original: arm9/ov013 @ 0x02186160; symbol: func_ov013_02186160; size: 0x390.
// Handles input for five bounded allocation values and transition selection.
extern "C" void UpdateFiveValueAllocationInput(unsigned char* p){
 p[0x6bc]|=1;p[0x638]=0;p[0x639]=0;Window_SelectCanvasById(p+0x38,0);
 int previous[6]={0};for(int i=0;i<5;i++)previous[i]=WI(0x688,i);
 int dirty=0,transition=0,next=-1;int oldIndex=W(0x65c);
 W(0x65c)=Selection_ReadEnabledIndexFromControl(p+0x38);
 if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x601)){
 if(W(0x65c)!=5){if(W(0x66c)==0){W(0x65c)=5;Window_SetEnabledSelectionIndices(p+0x38,5);W(0x64c)=0;dirty=1;}}else next=3;
 }else if(Window_ClassifyTouchAgainstSelectedCanvas(p+0x38)==2)next=4;
 else if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2)){if(previous[W(0x65c)]==0)next=4;}
 if(W(0x648)==0){
 if(W(0x66c)>=0&&W(0x65c)<5){
 if(Input_PollKeyRepeatCountdown((State*)KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,32)||Input_PollKeyRepeatCountdown((State*)KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2)||SkillAllocation_HitTestAdjustmentTouchRegion((Owner*)(p+0x38),10)){
 W(0x64c)=0;
 if(!*(p+W(0x65c)+0x69c)){
 (*(int*)(p+0x688+W(0x65c)*4))--;dirty=1;
 if(WI(0x688,W(0x65c))<0)WI(0x688,W(0x65c))=0;else Sound(93);
 }
 }else if(W(0x66c)>0){
 oldIndex=0;W(0x64c)=0;
 if(WI(0x674,W(0x65c))!=100&&WI(0x674,W(0x65c))+WI(0x688,W(0x65c))<100){
 if(Input_PollKeyRepeatCountdown((State*)KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x611)||SkillAllocation_HitTestAdjustmentTouchRegion((Owner*)(p+0x38),11)){
 if(!*(p+W(0x65c)+0x69c)){(*(int*)(p+0x688+W(0x65c)*4))++;oldIndex=1;dirty=oldIndex;}
 }
 if(oldIndex)SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,93,0);
 }
 }
 }
 }else{
 if(W(0x648)==2&&W(0x64c)==W(0x648)&&oldIndex==5&&W(0x65c)==5)next=3;
 dirty=1;W(0x64c)=W(0x648);
 }
 if(next>=0){W(0x64c)=0;p[0x63c]=next;p[0x665]=0;transition=1;dirty=transition;p[0x6bc]&=~1;
 if(!p[0x640]){Sound(1);Window_SelectCanvasById(p+0x38,4);Window_PopCanvasesAndResetSelection((State*)(p+0x38),0);}else Sound(5);
 if(p[0x640])SkillAllocation_InitializeSubScreenPromptPanel(p);else SkillAllocation_ShowMainScreenPrompt((char*)p);
 }
 int sum=0;for(int i=0;i<5;i++)sum+=WI(0x688,i);W(0x66c)=W(0x668)-sum;
 if(transition)SkillAllocation_SetTextRecordTransitionFlag(p,0,1);else if(dirty)Graphics_FormatFiveRowSelectionTextAndRefreshOwner(p);
}
