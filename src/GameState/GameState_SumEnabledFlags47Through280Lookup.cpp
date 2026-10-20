#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" {
// Original data: arm9/main @ 0x20e8ae2; symbol: data_020e8ae2.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 2f003300df00e800ec00ee001801ffff.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern short GameStateSumEnabledFlags47Through280Lookup_UnknownRoleInitializedBytes[];
    bool CharacterState_GetLearnedSkillMask(void *,int);
    int GameState_ReadAttributeBits12To19(GameState *,int);
// Original: arm9/main @ 0x0208608C; symbol: func_0208608c; size: 0x6C.
    int GameState_SumEnabledFlags47Through280Lookup(void *p){
        GameState *state=GameState::GetInstance();
        int count=0;
        unsigned char i=0;
        short id;
        while((id=GameStateSumEnabledFlags47Through280Lookup_UnknownRoleInitializedBytes[i])!=-1){
            if(CharacterState_GetLearnedSkillMask(p,id))count+=GameState_ReadAttributeBits12To19(state,id);
            i++;
        }return count;
    }
}
