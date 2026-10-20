#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" {
// Original data: arm9/main @ 0x20e8ad2; symbol: data_020e8ad2.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 4e0052005600ac00ea00fd000101ffff.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern short GameStateSumEnabledFlags78Through257Lookup_UnknownRoleInitializedBytes[];
    bool CharacterState_GetLearnedSkillMask(void *,int);
    int GameState_ReadAttributeBits12To19(GameState *,int);
// Original: arm9/main @ 0x020861D0; symbol: func_020861d0; size: 0x6C.
    int GameState_SumEnabledFlags78Through257Lookup(void *p){
        GameState *state=GameState::GetInstance();
        int count=0;
        unsigned char i=0;
        short id;
        while((id=GameStateSumEnabledFlags78Through257Lookup_UnknownRoleInitializedBytes[i])!=-1){
            if(CharacterState_GetLearnedSkillMask(p,id))count+=GameState_ReadAttributeBits12To19(state,id);
            i++;
        }return count;
    }
}
