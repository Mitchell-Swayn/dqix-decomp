#include <globaldefs.h>
ARM
#pragma opt_common_subs off
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void*);
extern "C" void* ZoneContainer_GetGlobalRenderParts();
extern "C" void FloatingNumber_DrawQueuedNumbers(void*);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void TextWindow_DrawAndTransferOptionalWindow(int);
extern "C" int OverlayLoader_GetSecondarySelectionOrMinusOne();
extern "C" void Graphics_CleanupActiveObjectResourceBlock(void*);
extern "C" void BattleMenu_RefreshPartyPanelTilemap(char*);
extern "C" void SkillAllocation_RefreshDisplayResources(void*);
extern "C" void SkillDetails_SubmitRewardMarkerSprites(void*);
extern "C" void Graphics_ClearInactiveResourceState(void*);
extern "C" void BattleHud_DrawPartyStatusPanels(void*);
extern "C" void BattleCombo_DrawAnimatedIndicator(void*);
extern "C" void BattleScene_DrawPartyCommandTargetMarkers(void*);

#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov000 @ 0x02160C84; symbol: Graphics_UpdateSelectedResourceBranchesAndReleaseReadyBuffer; size: 0xFC.
extern "C" void Graphics_UpdateSelectedResourceBranchesAndReleaseReadyBuffer(char* self){if(W(self,0x55f4)&0x200){if(P(self,0x55cc))Graphics_CleanupActiveObjectResourceBlock(P(self,0x55cc));if(P(self,0x5574)){BattleMenu_RefreshPartyPanelTilemap(self+0x3760);SkillAllocation_RefreshDisplayResources(P(self,0x5574));if(P(self,0x5578))SkillDetails_SubmitRewardMarkerSprites(P(self,0x5578));}else if(P(self,0x5588)){BattleMenu_RefreshPartyPanelTilemap(self+0x3760);Graphics_ClearInactiveResourceState(P(self,0x5588));}else if(!(W(self,0x55f4)&0x40000))BattleHud_DrawPartyStatusPanels(self+0x3760);FloatingNumber_DrawQueuedNumbers(ZoneContainer_GetGlobalRenderParts());BattleCombo_DrawAnimatedIndicator(self+0x6ffc);if(W(self,0xea8)==7&&OverlayLoader_GetSecondarySelectionOrMinusOne()==3)BattleScene_DrawPartyCommandTargetMarkers(self);}_ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());unsigned owner=TextContext_GetSharedInstance();if(W(owner,0x998))TextWindow_DrawAndTransferOptionalWindow(owner);}