#include <globaldefs.h>
ARM
#pragma opt_common_subs off
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant2[];extern "C" int Bgm_IsTemporarySequencePendingOrPlaying(void*);extern "C" void PartyGrowthPanel_ResetDisplay(void*);extern "C" void* Network_GetConnectionManager();extern "C" int Network_IsSessionActive(void*);extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" char* GameState_GetIndexList(void*);extern "C" void PartySync_QueueCurrentVocationProgress(int,int,int,int);extern "C" void* TextContext_GetSharedInstance();extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);extern "C" void Graphics_ClearAndStageSharedBuffers(void*);extern "C" void* SystemState_GetGlobalFlags();extern "C" void SystemState_ClearFlags(void*,unsigned);extern "C" void BattleScene_RequestPhase(void*,unsigned);extern "C" void Bgm_StopActiveSequenceUnlessBlocked(void*,unsigned);extern "C" void OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(int);
// Original: arm9/ov023 @ 0x021F3FBC; symbol: ResetSelectionAndQueueConnectedMembersBeforePop; size: 0xDC.
extern "C" unsigned BattleResults_FinishAndRestoreBattleScene(char* self){if(Bgm_IsTemporarySequencePendingOrPlaying(Main_UnknownRoleZeroInitializedStorage_Variant2))return W(self,0xeac);if(P(self,0x5588)){PartyGrowthPanel_ResetDisplay(P(self,0x5588));W(self,0x5588)=0;}if(Network_IsSessionActive(Network_GetConnectionManager())){char* indices=GameState_GetIndexList(_ZN9GameState11GetInstanceEv());int zero=0;int one=1;for(int i=0;i<B(indices,0xf7c);i++)PartySync_QueueCurrentVocationProgress(*(unsigned char*)((indices+i)+0xf78),zero,zero,one);}void* owner=TextContext_GetSharedInstance();TextWindow_ResetGlyphBuffersAndFrameContexts(owner);Graphics_ClearAndStageSharedBuffers(owner);SystemState_ClearFlags(SystemState_GetGlobalFlags(),0x20000);BattleScene_RequestPhase(self,4);Bgm_StopActiveSequenceUnlessBlocked(Main_UnknownRoleZeroInitializedStorage_Variant2,0);OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(1);return W(self,0xeac);}
