#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20e8aaa; symbol: data_020e8aaa.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex a800e10008010e011001ffff.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" short GameStateSumPresentAttributesFromSecondSentinelTable_UnknownRoleInitializedBytes[];extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" int CharacterState_GetLearnedSkillMask(void*,int);extern "C" int GameState_ReadAttributeBits12To19(void*,int);
// Original: arm9/main @ 0x02086164; symbol: func_02086164; size: 0x6C.
extern "C" int GameState_SumPresentAttributesFromSecondSentinelTable(void* p){void* state=_ZN9GameState11GetInstanceEv();int sum=0;unsigned i=0;while(GameStateSumPresentAttributesFromSecondSentinelTable_UnknownRoleInitializedBytes[i]!=-1){int key=GameStateSumPresentAttributesFromSecondSentinelTable_UnknownRoleInitializedBytes[i];if(CharacterState_GetLearnedSkillMask(p,key))sum+=GameState_ReadAttributeBits12To19(state,key);i=(i+1)&255;}return sum;}
