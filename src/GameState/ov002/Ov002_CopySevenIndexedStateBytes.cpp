#include <globaldefs.h>
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *_ZN9GameState14GetProtagonistEv(void *);
extern "C" void SetIndexedGameStateByteAtOffset2C8D(void *, int, unsigned char);
// Original: arm9/ov002 @ 0x0215AA14; symbol: func_ov002_0215aa14; size: 0x48.
extern "C" void Ov002_CopySevenIndexedStateBytes(char *source) {
    void *state = _ZN9GameState11GetInstanceEv();
    void *protagonist = _ZN9GameState14GetProtagonistEv(state);
    if (protagonist == 0) return;
    int i;
    for (i = 0; i < 7; i++) {
        volatile signed char *row = (volatile signed char *)(source + i + 0x1c00);
        ((void (*)(void *, int, int))SetIndexedGameStateByteAtOffset2C8D)(protagonist, i, *(signed char *)(row + 0x7c));
    }
}
