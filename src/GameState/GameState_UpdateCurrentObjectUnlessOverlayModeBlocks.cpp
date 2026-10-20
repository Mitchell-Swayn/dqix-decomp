#include "globaldefs.h"
#pragma optimize_for_size off
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* GameState_GetFieldVisualObject(void*);extern "C" int LinkedQueue_GetFrontKindOrInvalid(void*);extern "C" void LinkedQueue_GetFrontNode(void*);extern "C" void* Object_GetGlobalSixteenEntryDisplayState();extern "C" int FieldBattle_IsSceneActive(void*);extern "C" void FieldVisualActor_DrawWithHeightOffset(void*);extern "C" void UpdateInactiveEntriesForMatchingParentObject(void*,int);
// Original: arm9/main @ 0x020A66A4; symbol: func_020a66a4; size: 0x84.
extern "C" void GameState_UpdateCurrentObjectUnlessOverlayModeBlocks(unsigned char*p){void*object;int type;void*state;void*g=_ZN9GameState11GetInstanceEv();state=*(void**)(p+0x36fc);object=GameState_GetFieldVisualObject(g);type=LinkedQueue_GetFrontKindOrInvalid(state);LinkedQueue_GetFrontNode(state);p=*(unsigned char**)(p+0x3718);state=Object_GetGlobalSixteenEntryDisplayState();if(!object)return;if(type==10&&p[3]&&FieldBattle_IsSceneActive(p))return;FieldVisualActor_DrawWithHeightOffset(object);UpdateInactiveEntriesForMatchingParentObject(state,201);}
