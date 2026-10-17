#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"
// Original: arm9/main @ 0x0202445C; symbol: func_0202445c; size: 0xBC.
extern "C" ARM void CopyObjectXZAndClampScaledCoordinate(char* p)
{
    GameState* state=GameState::GetInstance();
    if(!state)return;
    char* object=(char*)state->GetUnknownGameObject();
    if(!object)return;
    *(int*)(p+0x5ac)=*(int*)(object+0x44);
    *(int*)(p+0x5b0)=*(int*)(object+0x4c);
    if(*(int*)(p+0x14)==3)
    {
        int negative=fix32_Divide(0x37000,*(int*)(p+0x38));
        int positive=fix32_Divide(0x1e000,*(int*)(p+0x38));
        int value=*(int*)(p+0x5b0);
        if(value<0)
        {
            if(value < -negative)*(int*)(p+0x5b0)=-(negative+value);
            else *(int*)(p+0x5b0)=0;
        }
        else if(value>0)
        {
            if(value>positive)*(int*)(p+0x5b0)=value-positive;
            else *(int*)(p+0x5b0)=0;
        }
        else *(int*)(p+0x5b0)=0;
    } else if(*(int*)(p+0x14)==4)*(int*)(p+0x5b0)=*(int*)(object+0x48);
}
