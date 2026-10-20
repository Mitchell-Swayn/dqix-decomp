#include <globaldefs.h>
ARM
struct State;struct GridSelection;
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void InitializeRightAlignedTwoChoicePanel(char*);
extern "C" void Grid_SelectIndexAndInvalidateTouchHistory(State*,int);
extern "C" void Grid_SelectIndexAndComputePageCoordinates(GridSelection*,int);
extern "C" int Object_ReadSelectionResultWhenGridReady(unsigned char*);
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
extern "C" int Selection_ReadEnabledIndexFromEmbeddedControl(unsigned char*);
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);
extern "C" void TextLayout_HidePanelImmediately(unsigned char*);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
extern "C" void Window_PopCanvasesAndResetSelection(State*,int);
extern "C" void Input_SuppressKeyRepeatUntilRelease(void*);
extern "C" void SkillAllocation_SetTextRecordTransitionFlag(void*,unsigned,int);
extern "C" void RefreshHeadingAndUploadFontTiles(char*);
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
// Original: arm9/ov013 @ 0x02186590; symbol: func_ov013_02186590; size: 0x1FC.
// Advances a two-choice confirmation control and applies acceptance or cancellation.
extern "C" void AdvanceConfirmationSelection(unsigned char* p){
 if(p[0x63f])p[0x639]=1;
 char* owner=(char*)TextContext_GetSharedInstance();bool sound=true;owner[0x19be]=1;
 if(p[0x63e]==0){
 if(*(int*)(owner+0x9a0))return;
 InitializeRightAlignedTwoChoicePanel((char*)p);unsigned char* selection=p+0x3f0;
 if(p[0x63c]==4){Grid_SelectIndexAndInvalidateTouchHistory((State*)(selection+4),1);Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(selection+0x54),1);}else{Grid_SelectIndexAndInvalidateTouchHistory((State*)(selection+4),0);Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(selection+0x54),0);}
 p[0x63e]++;
 }else if(p[0x63e]==1){
 int result=Object_ReadSelectionResultWhenGridReady(p+0x3d4);
 if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x601))result=Selection_ReadEnabledIndexFromEmbeddedControl(p+0x3d4);
 else if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2)){result=-2;sound=false;}
 switch(result){case 0:
 if(p[0x63c]==4){p[0x63c]=5;TextWindow_ResetGlyphBuffersAndFrameContexts(owner);TextLayout_HidePanelImmediately(p+0x3d4);p[0x664]=0;SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);}
 else{p[0x63c]=5;p[0x664]=1;TextWindow_ResetGlyphBuffersAndFrameContexts(owner);TextLayout_HidePanelImmediately(p+0x3d4);Window_PopCanvasesAndResetSelection((State*)(p+0x38),1);SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);}
 p[0x63e]=0;break;
 case -2:case 1:
 p[0x63c]=1;p[0x63e]=0;Input_SuppressKeyRepeatUntilRelease(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage);
 if(sound)SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
 p[0x664]=0;TextWindow_ResetGlyphBuffersAndFrameContexts(owner);TextLayout_HidePanelImmediately(p+0x3d4);p[0x639]=0;SkillAllocation_SetTextRecordTransitionFlag(p,0,0);RefreshHeadingAndUploadFontTiles((char*)p);break;
 }
 }
}
