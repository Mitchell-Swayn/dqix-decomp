#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetIndexList(void *);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov023 @ 0x021E9A78; symbol: func_ov023_021e9a78; size: 0x24.
extern "C" int SetOutputFieldFromGameStateIndexList(void *output) {
    void *game = _ZN9GameState11GetInstanceEv();
    void *list = GameState_GetIndexList(game);
    SetNestedSecondWordForTypeThree(output, *(int *)((char *)list + 0xf68));
    return 1;
}
