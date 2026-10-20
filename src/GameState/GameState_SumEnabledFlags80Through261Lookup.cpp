#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" {
// Original data: arm9/main @ 0x20e8a9e; symbol: data_020e8a9e.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 50005400650069000501ffff.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern short GameStateSumEnabledFlags80Through261Lookup_UnknownRoleInitializedBytes[];
    bool CharacterState_GetLearnedSkillMask(void *,int);
    int GameState_ReadAttributeBits12To19(GameState *,int);
// Original: arm9/main @ 0x02086314; symbol: func_02086314; size: 0x6C.
    int GameState_SumEnabledFlags80Through261Lookup(void *p){
        GameState *state=GameState::GetInstance();
        int count=0;
        unsigned char i=0;
        short id;
        while((id=GameStateSumEnabledFlags80Through261Lookup_UnknownRoleInitializedBytes[i])!=-1){
            if(CharacterState_GetLearnedSkillMask(p,id))count+=GameState_ReadAttributeBits12To19(state,id);
            i++;
        }return count;
    }
}
