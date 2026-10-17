#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned ReadWordFieldAtOffset1C(void*);
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void*);
extern "C" void Object_ConfigureTextCountThroughEmbeddedHandler(void*, int);
extern "C" void func_020439b0(void*, int);
// Original: arm9/ov017 @ 0x021C1DFC; symbol: func_ov017_021c1dfc; size: 0x38.
extern "C" void UpdateObjectTextCountFromTick() {
    void* gameState = _ZN9GameState11GetInstanceEv();
    unsigned* object = (unsigned*)ReadWordFieldAtOffset1C(gameState);
    unsigned tick = _ZNK9GameState12GetTickCountEv(gameState);
    Object_ConfigureTextCountThroughEmbeddedHandler(object, tick);
    func_020439b0(object, 0);
}
