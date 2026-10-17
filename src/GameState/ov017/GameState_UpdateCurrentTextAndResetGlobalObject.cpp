#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
extern "C" unsigned int _ZNK9GameState12GetTickCountEv(void *);
extern "C" void Object_ConfigureTextCountThroughEmbeddedHandler(void *, unsigned int);
extern "C" void func_020439b0(void *, int);
extern "C" void IgnoreEmbeddedOwnerState(void *);
// Original: arm9/ov017 @ 0x021A925C; symbol: func_ov017_021a925c; size: 0x44.
extern "C" void GameState_UpdateCurrentTextAndResetGlobalObject(void *owner) {
    void *state = _ZN9GameState11GetInstanceEv();
    void *object = (void *)ReadWordFieldAtOffset1C();
    unsigned int tick = _ZNK9GameState12GetTickCountEv(state);
    Object_ConfigureTextCountThroughEmbeddedHandler(object, tick);
    func_020439b0(object, 0);
    IgnoreEmbeddedOwnerState((unsigned char *)owner + 0x2c);
}
