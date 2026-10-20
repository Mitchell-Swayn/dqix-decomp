#include <globaldefs.h>
#include "GameState/GameState.h"
ARM
#pragma force_active on
extern "C" void* GameState_GetIndexList(GameState*);
// Original: arm9/ov003 @ 0x02161544; symbol: func_ov003_02161544; size: 0x78.
extern "C" int Tavern_CountLivingPartyMembersExceptSelected(void* menu) {
    char* self=(char*)menu;
    GameState* game=GameState::GetInstance();
    GameStateIndexList* list=(GameStateIndexList*)GameState_GetIndexList(game);
    unsigned char count=0;
    for(unsigned char i=0;i<list->count_;i++) {
        int index=list->objectIndices_[i];
        if(index==*(short*)(self+0x482)) continue;
        GameObject* object=game->GetCombatantByIndex(index);
        if(object && *(unsigned short*)(*(char**)((char*)object+0x130)+4)) count++;
    }
    return count;
}
