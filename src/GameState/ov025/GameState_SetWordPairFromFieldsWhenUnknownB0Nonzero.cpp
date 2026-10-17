#include <globaldefs.h>
ARM
struct GameState;
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_ReadUnknownB0(GameState *);
extern "C" void Object_SetWordPairAtOffset1E4WhenLengthNonzero(void *, int, unsigned int);
// Original: arm9/ov025 @ 0x021E8100; symbol: func_ov025_021e8100; size: 0x2C.
extern "C" int GameState_SetWordPairFromFieldsWhenUnknownB0Nonzero(void *settings) {
    void *state = _ZN9GameState11GetInstanceEv();
    void *object = GameState_ReadUnknownB0((GameState *)state);
    if (object)
        Object_SetWordPairAtOffset1E4WhenLengthNonzero(object, *(signed short *)((char *)settings + 0xa), *(unsigned short *)((char *)settings + 8));
    return 1;
}
