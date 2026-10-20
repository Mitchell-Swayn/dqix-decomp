#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20e8b02; symbol: data_020e8b02.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 9000960098009c00a2000a011601ffff.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" short GameStateSumPresentAttributesFromFirstSentinelTable_UnknownRoleInitializedBytes[];extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" int CharacterState_GetLearnedSkillMask(void*,int);extern "C" int GameState_ReadAttributeBits12To19(void*,int);
// Original: arm9/main @ 0x02086020; symbol: func_02086020; size: 0x6C.
extern "C" int GameState_SumPresentAttributesFromFirstSentinelTable(void* p){void* state=_ZN9GameState11GetInstanceEv();int sum=0;unsigned i=0;while(GameStateSumPresentAttributesFromFirstSentinelTable_UnknownRoleInitializedBytes[i]!=-1){int key=GameStateSumPresentAttributesFromFirstSentinelTable_UnknownRoleInitializedBytes[i];if(CharacterState_GetLearnedSkillMask(p,key))sum+=GameState_ReadAttributeBits12To19(state,key);i=(i+1)&255;}return sum;}
