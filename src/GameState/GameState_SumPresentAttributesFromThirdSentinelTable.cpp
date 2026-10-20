#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20e8bec; symbol: data_020e8bec.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 340094009e00c600ca00ce00e500f0000c01ffff.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" short GameStateSumPresentAttributesFromThirdSentinelTable_UnknownRoleInitializedBytes[];extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" int CharacterState_GetLearnedSkillMask(void*,int);extern "C" int GameState_ReadAttributeBits12To19(void*,int);
// Original: arm9/main @ 0x020862A8; symbol: func_020862a8; size: 0x6C.
extern "C" int GameState_SumPresentAttributesFromThirdSentinelTable(void* p){void* state=_ZN9GameState11GetInstanceEv();int sum=0;unsigned i=0;while(GameStateSumPresentAttributesFromThirdSentinelTable_UnknownRoleInitializedBytes[i]!=-1){int key=GameStateSumPresentAttributesFromThirdSentinelTable_UnknownRoleInitializedBytes[i];if(CharacterState_GetLearnedSkillMask(p,key))sum+=GameState_ReadAttributeBits12To19(state,key);i=(i+1)&255;}return sum;}
