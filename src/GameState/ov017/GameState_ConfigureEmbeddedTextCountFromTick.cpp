#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned ReadWordFieldAtOffset1C(void*);
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void*);
extern "C" void Object_ConfigureTextCountThroughEmbeddedHandler(void*, int);
extern "C" void func_020439b0(void*, int);
// Original: arm9/ov017 @ 0x021A9638; symbol: func_ov017_021a9638; size: 0x38.
extern "C" void GameState_ConfigureEmbeddedTextCountFromTick() {
    void* game = _ZN9GameState11GetInstanceEv();
    unsigned count = ReadWordFieldAtOffset1C(game);
    unsigned tick = _ZNK9GameState12GetTickCountEv(game);
    Object_ConfigureTextCountThroughEmbeddedHandler((void*)count, (int)tick);
    func_020439b0((void*)count, 0);
}
