#include <globaldefs.h>
#pragma optimization_level 4
#include "GameState/GameState.h"
extern "C" GameObject* GameState_GetValidObjectByIndex(GameState*,int);
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
extern "C" int TestSelectedEntryField2F4Bit22(void*);
extern "C" void* GetFieldAddress114(void*);
extern "C" int IsHalfwordLowFiveBitsOne(void*);
extern "C" int PackedColor_TestRedEqualsTwo(void*);
extern "C" int TestWordIndex1LowBitsEqualThree(void*);
extern "C" int IsHalfwordLowFiveBitsFour(void*);
extern "C" int ReadByteFieldAtOffset26C(void*);
// Original: arm9/main @ 0x0208AA28; symbol: func_0208aa28; size: 0x10C.
extern "C" ARM int TestObjectAvailableAndValidationFlags(char* p,int index,int flag)
{
    GameResources_GetInstance();
    GameState* state=GameState::GetInstance();
    char* member=(char*)GameState_GetValidObjectByIndex(state,index);
    char* other=(char*)GameState_GetObjectWithFlag100(state,index);
    if(!member||(**(unsigned**)(member+0x130)&1))return false;
    if(TestSelectedEntryField2F4Bit22(*(void**)(other+0x150)) || flag)return false;
    void* current=GetFieldAddress114(member);
    switch((unsigned char)p[4])
    {
        case 0:if(!IsHalfwordLowFiveBitsOne(current))return false;
        break;
        case 1:if(!PackedColor_TestRedEqualsTwo(current))return false;
        break;
        case 2:if(!TestWordIndex1LowBitsEqualThree(current))return false;
        break;
        case 3:if(!IsHalfwordLowFiveBitsFour(current))return false;
    }
    char* object=(char*)state->GetUnknownGameObject();
    if(!*(short*)(object+0xb2))return 0;
    int result=ReadByteFieldAtOffset26C(object);
    return result==0;
}
