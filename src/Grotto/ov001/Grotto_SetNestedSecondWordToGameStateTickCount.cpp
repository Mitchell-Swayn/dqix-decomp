#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" unsigned int _ZNK9GameState12GetTickCountEv(void *);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);

// Original: arm9/ov001 @ 0x02163284; symbol: func_ov001_02163284; size: 0x24.
extern "C" int Grotto_SetNestedSecondWordToGameStateTickCount(void *object) {
    void *gameState = _ZN9GameState11GetInstanceEv();
    unsigned int tick = _ZNK9GameState12GetTickCountEv(gameState);
    SetNestedSecondWordForTypeThree(object, tick);
    return 1;
}
