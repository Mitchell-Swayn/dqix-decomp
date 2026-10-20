#include <globaldefs.h>
#pragma optimization_level 4
#include "GameState/GameState.h"
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
extern "C" int GameResources_GetMaskedSecondaryFlags(void*,int);
extern "C" int GameObject_GetLadderTraversalActive(void*);
// Original: arm9/main @ 0x0208AE00; symbol: func_0208ae00; size: 0xBC.
extern "C" ARM int TestLinkedFlagsAndObjectStatusEligibility(char* p,int index)
{
    char* context=(char*)GameResources_GetInstance();
    GameState* state=GameState::GetInstance();
    char* first=(char*)GameState_GetObjectWithFlag100(state,index);
    char* second=(char*)GameState_GetObjectWithFlag100(state,index);
    if(!first || (**(unsigned**)(first+0x130)&1))return false;
    if(!(**(unsigned**)(second+0x130)&2))return false;
    if(GameResources_GetMaskedSecondaryFlags(context,16))return false;
    if(*(int*)(p+28))return false;
    char* object=(char*)state->GetUnknownGameObject();
    if(!*(short*)(object+0xb2))return 0;
    int result=GameObject_GetLadderTraversalActive(object);
    return result==0;
}
