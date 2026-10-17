#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* _ZN9GameState14GetProtagonistEv(void*);
unsigned char *ReadWordFieldAtOffset150(void*);
void SetNestedSecondWordForTypeThree(void*, int);
// Original: arm9/ov001 @ 0x02161D54; symbol: func_ov001_02161d54; size: 0x38.
int GameState_SetNestedStateFromProtagonistFlag(void *p) {
    void *game = _ZN9GameState11GetInstanceEv();
    void *protagonist = _ZN9GameState14GetProtagonistEv(game);
    unsigned char *field = ReadWordFieldAtOffset150(protagonist);
    int value = (((unsigned int)((int)field[0x49c] << 31)) >> 31) == 0;
    SetNestedSecondWordForTypeThree(p, value);
    return 1;
}
}
