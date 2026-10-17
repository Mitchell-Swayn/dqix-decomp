#include <globaldefs.h>
#include <GameState/GameState.h>

extern "C" ARM void* GameState_GetIndexList(void*);
// Original: arm9/ov003 @ 0x02160BD0; symbol: func_ov003_02160bd0; size: 0x28.
extern "C" ARM void* GameState_GetIndexedRecordAtF80(void* unused, int index) {
    if (index < 0) return 0;
    char* state = (char*)GameState_GetIndexList(GameState::GetInstance());
    return state + 0xf80 + 0x23c * index;
}
