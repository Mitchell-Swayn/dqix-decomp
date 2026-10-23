// Original: arm9/ov002 @ 0x02155DBC; symbol: PartyMenu_DrawCanvasesAndSprites; size: 0x190.
#include <globaldefs.h>
ARM
struct A;struct Obj;
extern "C" {
void Graphics_RefreshTransfersAndSubmitSelectedFortyByteRecord(char*);
void Graphics_CleanupActiveObjectResourceBlock(void*);
void SkillAllocation_RefreshDisplayResources(unsigned char*);
void Window_ClearResourceBuffers(unsigned char*);
void ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void*);
void Window_FillCanvasRectanglesOnAlternateLayer(void*,int,int,int);
void Graphics_ResetCountedThirtyTwoByteTransfers(unsigned char*);
void PartyMenu_PositionCommandSlotSprites(char*);
void PartyMenu_RebuildPanelTextById(void*,unsigned,unsigned);
void PartyMenu_LoadMemberVocationFontPalette(int,unsigned char*,unsigned char*);
void PartyMenu_PositionMemberAndHeadingSprites(char*);
void Graphics_UpdateFourByFourSelectionGrid(char*);
void PartyMenu_AnimateSelectionCursor(unsigned char*);
void Graphics_ResetFirstResourceEntryWhenFlagEight(char*);
void PartyMenu_DrawBagSortIndicators(char*);
unsigned Window_IsVisible(A**);
void Window_UpdateEnabledEntryAndRoot(Obj*,void*);
}
extern "C" void PartyMenu_DrawCanvasesAndSprites(char* self){
if(*(unsigned char*)(self+0x1cc3))Graphics_RefreshTransfersAndSubmitSelectedFortyByteRecord(self+0x8b4);
if(*(void**)(self+0x2468))Graphics_CleanupActiveObjectResourceBlock(*(void**)(self+0x2468));
if(*(int*)(self+0x1bb8)==30&&*(int*)(self+0x1bc0)>4)SkillAllocation_RefreshDisplayResources((unsigned char*)self+0x1d70);
else{
unsigned char* window=(unsigned char*)self+0xec8;
Window_ClearResourceBuffers(window);ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(window);Window_FillCanvasRectanglesOnAlternateLayer(window,1,2,1);Window_FillCanvasRectanglesOnAlternateLayer(window,1,3,1);Window_FillCanvasRectanglesOnAlternateLayer(window,2,3,0);Graphics_ResetCountedThirtyTwoByteTransfers(window);PartyMenu_PositionCommandSlotSprites(self);
if(*(unsigned char*)(self+0x1c34)){PartyMenu_RebuildPanelTextById(self,27,0);PartyMenu_RebuildPanelTextById(self,26,0);PartyMenu_LoadMemberVocationFontPalette(*(signed char*)(self+0x1c20),*(unsigned char**)(self+0x1a68),*(unsigned char**)(self+0x1bd8));*(unsigned char*)(self+0x1c34)=0;}
PartyMenu_PositionMemberAndHeadingSprites(self);Graphics_UpdateFourByFourSelectionGrid(self);PartyMenu_AnimateSelectionCursor((unsigned char*)self);Graphics_ResetFirstResourceEntryWhenFlagEight(self);PartyMenu_DrawBagSortIndicators(self);
}
if(*(void**)self&&Window_IsVisible(*(A***)self))Window_UpdateEnabledEntryAndRoot(*(Obj**)self,0);
if(*(void**)(self+4)&&Window_IsVisible(*(A***)(self+4)))Window_UpdateEnabledEntryAndRoot(*(Obj**)(self+4),*(void**)(self+0x1a68));
}
