#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned ReadWordFieldAtOffset1C();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void*);
extern "C" void Object_ConfigureTextCountThroughEmbeddedHandler(void*, int);
extern "C" void func_020439b0(void*, unsigned);
// Original: arm9/ov017 @ 0x021BF360; symbol: func_ov017_021bf360; size: 0x38.
extern "C" void GameState_UpdateTextHandlerFromTick(void) {
    void* state = _ZN9GameState11GetInstanceEv();
    void* object = (void*)ReadWordFieldAtOffset1C();
    Object_ConfigureTextCountThroughEmbeddedHandler(object, _ZNK9GameState12GetTickCountEv(state));
    func_020439b0(object, 0);
}
