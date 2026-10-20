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
// Original: arm9/main @ 0x020A1034; symbol: func_020a1034; size: 0x74.
extern "C" void VectorTransition_ApproachTarget(char* p){Vector3fix v;Vector3fix_Subtract((Vector3fix*)(p+16),(Vector3fix*)(p+4),&v);if(Vector3fix_Length(&v)<409){*(Vector3i*)(p+4)=*(Vector3i*)(p+16);*(int*)p=0;}else{Vector3fix out;Vector3fixDivideScalar(&v,*(int*)(p+36),&out);Vector3fix_Add((Vector3fix*)(p+4),&out,(Vector3fix*)(p+4));}}
