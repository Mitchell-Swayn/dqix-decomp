#include <globaldefs.h>
ARM
extern "C" void GameState_SetRequestedDayTimer(float, void *);
// Original: arm9/ov017 @ 0x021CDAE4; symbol: func_ov017_021cdae4; size: 0x1C.
extern "C" void SetGameStateFloatWhenConditionClear(int condition, void *holder, float value) {
    if (condition == 0)
        GameState_SetRequestedDayTimer(value, *(void **)((char *)holder + 4));
}
