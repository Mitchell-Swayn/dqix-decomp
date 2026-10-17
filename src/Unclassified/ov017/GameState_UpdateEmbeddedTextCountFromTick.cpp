#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *ReadWordFieldAtOffset1C(void);
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void *state);
extern "C" void Object_ConfigureTextCountThroughEmbeddedHandler(void *object, unsigned count);
extern "C" void func_020439b0(void *object, int value);
// Original: arm9/ov017 @ 0x021BE3B4; symbol: func_ov017_021be3b4; size: 0x38.
extern "C" void GameState_UpdateEmbeddedTextCountFromTick(void) {
    void *state = _ZN9GameState11GetInstanceEv();
    void *object = ReadWordFieldAtOffset1C();
    Object_ConfigureTextCountThroughEmbeddedHandler(object, _ZNK9GameState12GetTickCountEv(state));
    func_020439b0(object, 0);
}
