struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
struct GameState;struct State;struct GridSelection;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(GameState*);
extern "C" WindowCanvasRecord* Window_GetTopTextCanvas(WindowCanvasOwner*);
extern "C" bool TextCanvas_IsReady(int);
extern "C" void Grid_SetLastTouchIndex(void*,int);
extern "C" int Window_UpdateCanvasesAndSelection(unsigned char*,unsigned);
extern "C" void UpdateEmbeddedDisplayContextWhenEnabled(unsigned char*,int);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void SpriteAnimation_AdvanceAllTracks(char*,unsigned);
extern "C" void Grid_ResetTouchTracking(char*);
extern "C" void Grid_SetOrientationAndCoordinatePointers(unsigned char*,int,int,int);
extern "C" void Grid_SetEntryCountAndClampSelection(int*,int);
extern "C" void Grid_SelectIndexAndInvalidateTouchHistory(State*,int);
extern "C" void Grid_SelectIndexAndComputePageCoordinates(GridSelection*,int);
extern "C" void Graphics_FormatFiveRowSelectionTextAndRefreshOwner(void*);
extern "C" void AdvanceHeadingResourceInitialization(unsigned char*);
extern "C" void UpdateFiveValueAllocationInput(unsigned char*);
extern "C" void SkillAllocation_HandleSubScreenNoticeInput(char*);
extern "C" void SkillAllocation_HandleMainScreenNoticeInput(unsigned char*);
extern "C" void UpdateTwoChoiceAllocationConfirmation(unsigned char*);
extern "C" void AdvanceConfirmationSelection(unsigned char*);
extern "C" void Graphics_DestroyModeDependentPanelAndTwoAllocators(unsigned char*);
extern "C" void Window_SetCanvasDisplayAttribute(char*,int,int);
// Original: arm9/ov013 @ 0x021847C4; symbol: func_ov013_021847c4; size: 0x294.
// Updates display controls, handles state-entry layout changes, and dispatches allocation overlay states.
#pragma force_active on
extern "C" unsigned UpdateAllocationOverlayFrame(unsigned char* p,unsigned value){
 *(unsigned*)(p+0x14)=value;GameState* game=(GameState*)_ZN9GameState11GetInstanceEv();*(unsigned*)(p+0x644)=_ZNK9GameState12GetTickCountEv(game);
 unsigned char* record=(unsigned char*)Window_GetTopTextCanvas((WindowCanvasOwner*)(p+0x38));
 if(record&&TextCanvas_IsReady((int)record)&&!(record[0xc5]&2))Grid_SetLastTouchIndex(p+0x3c,-1);
 *(int*)(p+0x648)=Window_UpdateCanvasesAndSelection(p+0x38,*(unsigned*)(p+0x644));UpdateEmbeddedDisplayContextWhenEnabled(p+0x3d4,*(unsigned*)(p+0x644));
 char* entries=*(char**)(TextContext_GetSharedInstance()+0x2e0);if(entries)SpriteAnimation_AdvanceAllTracks(entries,_ZNK9GameState12GetTickCountEv(game));
 if(p[0x63f]){
 if(p[0x640])Grid_ResetTouchTracking((char*)p+0x3c);
 if(p[0x63c]==1){p[0xe9]=0;*(int*)(p+0x40)=1;*(int*)(p+0x90)=1;
 Grid_SetOrientationAndCoordinatePointers(p+0x3c,1,6,0);Grid_SetOrientationAndCoordinatePointers(p+0x8c,1,6,0);
 Grid_SetEntryCountAndClampSelection((int*)(p+0x3c),6);Grid_SetEntryCountAndClampSelection((int*)(p+0x8c),6);
 int index=*(int*)(p+0x65c);Grid_SelectIndexAndInvalidateTouchHistory((State*)(p+0x3c),index);Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(p+0x8c),index);Graphics_FormatFiveRowSelectionTextAndRefreshOwner(p);
 }
 if(p[0x63c]==3&&p[0x640]){p[0xe9]=3;*(int*)(p+0x40)=1;*(int*)(p+0x90)=1;
 Grid_SetOrientationAndCoordinatePointers(p+0x3c,1,2,0);Grid_SetOrientationAndCoordinatePointers(p+0x8c,1,2,0);
 Grid_SetEntryCountAndClampSelection((int*)(p+0x3c),2);Grid_SetEntryCountAndClampSelection((int*)(p+0x8c),2);
 Grid_SelectIndexAndInvalidateTouchHistory((State*)(p+0x3c),0);Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(p+0x8c),0);
 }
 p[0x63f]=0;return p[0x63c];
 }
 switch(p[0x63c]){
 case 0:AdvanceHeadingResourceInitialization(p);break;
 case 1:UpdateFiveValueAllocationInput(p);break;
 case 2:if(p[0x640])SkillAllocation_HandleSubScreenNoticeInput((char*)p);else SkillAllocation_HandleMainScreenNoticeInput(p);break;
 case 3:case 4:if(p[0x640])UpdateTwoChoiceAllocationConfirmation(p);else AdvanceConfirmationSelection(p);break;
 case 5:Graphics_DestroyModeDependentPanelAndTwoAllocators(p);break;
 }
 for(int i=0;i<4;i++)Window_SetCanvasDisplayAttribute((char*)p+0x38,(unsigned char)i,*(p+i+0x638));
 p[0x63f]=(p[0x63c]!=p[0x63d]);p[0x63d]=p[0x63c];return p[0x63c];
}
