#include <globaldefs.h>
#include <GameState/GameState.h>

extern "C" ARM void* GameState_GetIndexList(void*);
extern "C" ARM unsigned _u32_div_f(unsigned,unsigned);
// Original: arm9/ov003 @ 0x02179E18; symbol: func_ov003_02179e18; size: 0x2C.
extern "C" ARM unsigned Shop_GetSaleQuantityWithinGoldLimit(void* action) {
    unsigned now=*(unsigned*)((char*)GameState_GetIndexList(GameState::GetInstance())+0xf6c);
    return _u32_div_f(0x0098967f-now,*(unsigned short*)((char*)action+0x1a));
}
