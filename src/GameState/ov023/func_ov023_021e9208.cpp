#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_ReadWordAtOffset5CB0(void*);
extern "C" int GameState_ReadUnknown5cb4(void*);
extern "C" void SetNestedSecondWordForTypeThree(void*, int);
// Original: arm9/ov023 @ 0x021E9208; symbol: func_ov023_021e9208; size: 0x3C.
extern "C" int func_ov023_021e9208(void* p) {
    void* gameState = _ZN9GameState11GetInstanceEv();
    SetNestedSecondWordForTypeThree(p, GameState_ReadWordAtOffset5CB0(gameState));
    SetNestedSecondWordForTypeThree((char*)p + 8, GameState_ReadUnknown5cb4(gameState));
    return 1;
}
