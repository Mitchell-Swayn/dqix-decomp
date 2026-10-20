#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
// Original data: arm9/main @ 0x20e8ab6; symbol: data_020e8ab6.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 2d0031009200c800cc00dd00ffff.
// Observed span: 14 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e8ac4; symbol: data_020e8ac4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 9a00a000ae0014011a011c01ffff.
// Observed span: 14 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e8af2; symbol: data_020e8af2.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 63006b006c00aa00e300ff000301ffff.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {void GameState_ClearByteSlots(GameState*);void GameState_EmitObjectPositionAndZoneRequest(void*,int);int ComputeMaskedIndexPopulationStrideAndBase(void*,unsigned,const void*,int);void Text_ParseDelimitedSignedIntegerSequence(void*,void*,int);char* TextContext_GetSharedInstance();void* func_02001a40(void*,const void*,unsigned);void Texture_FlushAndStageImageSegmentsAndPalette(void*);void func_02037640(void*);int String_CountBytesUntilTerminator(const char*);void TextWindow_SelectFrameTransitionRecord(void*,const void*);void WindowFrame_AdvanceCloseTransition(void*,int);void TextWindow_SelectPrimaryFrameTransition(void*);int TextLayout_IsPanelVisible(void*);void Selection_UpdateTouchAndDirectionalControls(void*,int);int CharacterState_GetLearnedSkillMask(void*,int);int GameState_ReadAttributeBits12To19(GameState*,int);extern short GameStateSumEnabledFlags45Through221Lookup_UnknownRoleInitializedBytes[],GameStateSumEnabledFlags154Through284Lookup_UnknownRoleInitializedBytes[],GameStateSumEnabledAttributeValuesFromSentinelIds_UnknownRoleInitializedBytes[];}
#pragma force_active on
// Original: arm9/main @ 0x02085FB4; symbol: func_02085fb4; size: 0x6C.
extern "C" int GameState_SumEnabledFlags45Through221Lookup(void* p){GameState* state=GameState::GetInstance();int total=0;for(unsigned char i=0;GameStateSumEnabledFlags45Through221Lookup_UnknownRoleInitializedBytes[i]!=-1;++i){int id=GameStateSumEnabledFlags45Through221Lookup_UnknownRoleInitializedBytes[i];if(CharacterState_GetLearnedSkillMask(p,id))total+=GameState_ReadAttributeBits12To19(state,id);}return total;}
