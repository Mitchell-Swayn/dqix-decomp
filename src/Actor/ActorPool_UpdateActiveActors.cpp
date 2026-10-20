// Exact original field widths and relocation-linked data/callee contracts reviewed; no wrapper addresses.
#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Matrix.h>
ARM
#pragma force_active on
// Original data: arm9/main @ 0x20e8b36; symbol: data_020e8b36.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e8b48; symbol: data_020e8b48.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e8b7e; symbol: data_020e8b7e.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct F14{unsigned a:14,flag:1,b:17;};struct F17{unsigned a:17,flag:1,b:14;};struct F21{unsigned a:21,flag:1,b:10;};struct Signed3{unsigned a:6;signed value:3;unsigned b:23;};typedef int(*Reader)(void**);extern "C" {extern signed char CharacterStateCountActiveMappedModifierBit14_UnknownRoleInitializedBytes[],CharacterStateTestActiveMappedModifierBit17_UnknownRoleInitializedBytes[],CharacterStateTestActiveMappedModifierBit21_UnknownRoleInitializedBytes[];unsigned GameState_ReadUnknownB0(GameState*);void Actor_AdvanceMotionLightingAndAuxiliaryTransform(void*,unsigned,unsigned,unsigned);unsigned GameState_CopyActivePartySlotList(GameState*,void*);void CombatStatus_ClearAgilityStage(void*);void* GameObject_GetLinkedIndexedState(void*);int GameState_ReadAttributeBits12To19(GameState*,int);}void Vector3fixDivideScalar(const Vector3fix*,int,Vector3fix*);
// Original: arm9/main @ 0x0203DD20; symbol: func_0203dd20; size: 0x74.
extern "C" void ActorPool_UpdateActiveActors(char* p){GameState* state=GameState::GetInstance();unsigned a=GameState_ReadUnknownB0(state),b=state->GetEffectiveDeltaTime(),c=state->GetTickCount();for(int i=0;i<32;++i){char* q=*(char**)(p+i*4+12);if(q&&!(*(unsigned*)q&0x8000))Actor_AdvanceMotionLightingAndAuxiliaryTransform(q,a,b,c);}}
