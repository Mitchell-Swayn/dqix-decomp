#include <globaldefs.h>
ARM
#pragma always_inline on
#include <GameState/GameState.h>
extern "C" float GameState_GetRequestedDayTimer(GameState*);
extern "C" void GameState_SetRequestedDayTimer(GameState*,float);
extern "C" char* _ZN15LightingManager11GetInstanceEv();
// Original data: arm9/ov017 @ 0x21d837c; symbol: data_ov017_021d837c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" float GameStateAlignRequestedDayTimerToTransition_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov017 @ 0x21d75b8; symbol: data_ov017_021d75b8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000040ffffffff000034430000f0410000f04100003443.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" float FieldAdvanceZoneEntryTransition_UnknownRoleInitializedBytes[];
struct Owner {char pad[12];unsigned char low:4,high:4;};
// Original: arm9/ov017 @ 0x0219C774; symbol: func_ov017_0219c774; size: 0x314.
// Aligns requested day timer around transition windows and updates lighting when permitted.
extern "C" int GameState_AlignRequestedDayTimerToTransition(Owner *owner,int apply){
 GameState *game=GameState::GetInstance();float value=GameState_GetRequestedDayTimer(game);float saved=value;
 if(apply&&owner&&!owner->low){game->SetDayTimer(value);GameState_SetRequestedDayTimer(game,value);char *lighting=_ZN15LightingManager11GetInstanceEv();*(float*)(lighting+0x94)=game->GetDayTimer();*(int*)(lighting+0x98)=game->GetTimeOfDay();return 0;}
 int part=0;if(value>=GameStateAlignRequestedDayTimerToTransition_UnknownRoleZeroInitializedStorage[2])part=3;else if(value>=GameStateAlignRequestedDayTimerToTransition_UnknownRoleZeroInitializedStorage[1])part=2;else if(value>=GameStateAlignRequestedDayTimerToTransition_UnknownRoleZeroInitializedStorage[3])part=1;int current=game->GetTimeOfDay();
 if(part==current){
 float ends[4]={GameStateAlignRequestedDayTimerToTransition_UnknownRoleZeroInitializedStorage[3],GameStateAlignRequestedDayTimerToTransition_UnknownRoleZeroInitializedStorage[1],GameStateAlignRequestedDayTimerToTransition_UnknownRoleZeroInitializedStorage[2],GameStateAlignRequestedDayTimerToTransition_UnknownRoleZeroInitializedStorage[2]+FieldAdvanceZoneEntryTransition_UnknownRoleInitializedBytes[4]};
 for(int i=0;i<4;i++){float window=FieldAdvanceZoneEntryTransition_UnknownRoleInitializedBytes[0];if(ends[i]-2.0f*window<value&&value<ends[i]){value=ends[i]-2.0f*window;saved=ends[i];}}
 if(GameStateAlignRequestedDayTimerToTransition_UnknownRoleZeroInitializedStorage[5]<=saved)saved=0;
 if(!owner||owner->low)value=saved;
 }
 if((part+1)%4==current){
 float ends[4]={GameStateAlignRequestedDayTimerToTransition_UnknownRoleZeroInitializedStorage[3],GameStateAlignRequestedDayTimerToTransition_UnknownRoleZeroInitializedStorage[1],GameStateAlignRequestedDayTimerToTransition_UnknownRoleZeroInitializedStorage[2],GameStateAlignRequestedDayTimerToTransition_UnknownRoleZeroInitializedStorage[2]+FieldAdvanceZoneEntryTransition_UnknownRoleInitializedBytes[4]};
 float starts[4]={GameStateAlignRequestedDayTimerToTransition_UnknownRoleZeroInitializedStorage[4],GameStateAlignRequestedDayTimerToTransition_UnknownRoleZeroInitializedStorage[3],GameStateAlignRequestedDayTimerToTransition_UnknownRoleZeroInitializedStorage[1],GameStateAlignRequestedDayTimerToTransition_UnknownRoleZeroInitializedStorage[2]};
 if(ends[part]-2.0f*FieldAdvanceZoneEntryTransition_UnknownRoleInitializedBytes[0]<value&&value<ends[part]){value=starts[current];saved=value;}
 }
 part=0;if(value>=GameStateAlignRequestedDayTimerToTransition_UnknownRoleZeroInitializedStorage[2])part=3;else if(value>=GameStateAlignRequestedDayTimerToTransition_UnknownRoleZeroInitializedStorage[1])part=2;else if(value>=GameStateAlignRequestedDayTimerToTransition_UnknownRoleZeroInitializedStorage[3])part=1;if(part==current)apply=1;
 if(apply){game->SetDayTimer(value);GameState_SetRequestedDayTimer(game,saved);char *lighting=_ZN15LightingManager11GetInstanceEv();*(float*)(lighting+0x94)=game->GetDayTimer();*(int*)(lighting+0x98)=game->GetTimeOfDay();}
 return part!=current;
}
