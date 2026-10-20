#include <globaldefs.h>
#pragma optimization_level 4
#include "GameState/GameState.h"
extern "C" GameObject* GameState_GetValidObjectByIndex(GameState*,int);
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
extern "C" int CharacterState_TestActiveMappedModifierBit22(void*);
extern "C" void* GameObject_GetFloorContactDescriptor(void*);
extern "C" int GameObject_TestValidationKindOne(void*);
extern "C" int GameObject_TestValidationKindTwo(void*);
extern "C" int ActorDescriptor_IsValidationKindThree(void*);
extern "C" int ActorDescriptor_IsValidationKindFour(void*);
extern "C" int GameObject_GetLadderTraversalActive(void*);
// Original: arm9/main @ 0x0208AA28; symbol: func_0208aa28; size: 0x10C.
extern "C" ARM int TestObjectAvailableAndValidationFlags(char* p,int index,int flag)
{
    GameResources_GetInstance();
    GameState* state=GameState::GetInstance();
    char* member=(char*)GameState_GetValidObjectByIndex(state,index);
    char* other=(char*)GameState_GetObjectWithFlag100(state,index);
    if(!member||(**(unsigned**)(member+0x130)&1))return false;
    if(CharacterState_TestActiveMappedModifierBit22(*(void**)(other+0x150)) || flag)return false;
    void* current=GameObject_GetFloorContactDescriptor(member);
    switch((unsigned char)p[4])
    {
        case 0:if(!GameObject_TestValidationKindOne(current))return false;
        break;
        case 1:if(!GameObject_TestValidationKindTwo(current))return false;
        break;
        case 2:if(!ActorDescriptor_IsValidationKindThree(current))return false;
        break;
        case 3:if(!ActorDescriptor_IsValidationKindFour(current))return false;
    }
    char* object=(char*)state->GetUnknownGameObject();
    if(!*(short*)(object+0xb2))return 0;
    int result=GameObject_GetLadderTraversalActive(object);
    return result==0;
}
