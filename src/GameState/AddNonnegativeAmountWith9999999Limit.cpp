#include <globaldefs.h>
#include <GameState/GameState.h>

extern "C" void* GameState_GetIndexList(GameState* state);

// Original: arm9/main @ 0x0207D2C4; symbol: func_0207d2c4; size: 0x3C.
extern "C" ARM int AddNonnegativeAmountWith9999999Limit(void*, int amount)
{
    if (amount < 0)
        return 0;

    unsigned int maximum = 0x0098967f;
    unsigned char* list = (unsigned char*)GameState_GetIndexList(GameState::GetInstance());
    if (maximum - (unsigned int)amount >= *(unsigned int*)(list + 0xf6c))
        *(unsigned int*)(list + 0xf6c) = *(unsigned int*)(list + 0xf6c) + amount;
    else
        *(unsigned int*)(list + 0xf6c) = maximum;
    return 1;
}
