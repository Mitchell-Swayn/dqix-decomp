#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" int GameState_ReadWordAtOffset5CB0(void *);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov001 @ 0x02162D3C; symbol: func_ov001_02162d3c; size: 0x2C.
extern "C" int Grotto_SetNestedSecondWordFromStateThreshold(void *object) {
    int value = GameState_ReadWordAtOffset5CB0(_ZN9GameState11GetInstanceEv());
    SetNestedSecondWordForTypeThree(object, value >= 0x13);
    return 1;
}
