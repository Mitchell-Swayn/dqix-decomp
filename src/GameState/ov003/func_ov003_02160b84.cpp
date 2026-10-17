#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void* GameState_GetValidObjectByIndex(void*, int);
extern "C" void* GameState_GetIndexList(void*);
// Original: arm9/ov003 @ 0x02160B84; symbol: func_ov003_02160b84; size: 0x4C.
extern "C" int func_ov003_02160b84(void) {
    void* gameState = _ZN9GameState11GetInstanceEv();
    int valid = 0;
    for (int i = 0; i < 4; ++i) {
        if (GameState_GetValidObjectByIndex(gameState, i)) ++valid;
    }
    unsigned char count = *((unsigned char*)GameState_GetIndexList(_ZN9GameState11GetInstanceEv()) + 0xf7c);
    return valid - count;
}
