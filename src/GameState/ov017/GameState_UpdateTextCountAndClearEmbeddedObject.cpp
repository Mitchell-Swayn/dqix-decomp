#include <globaldefs.h>
ARM
struct GameState;
extern "C" GameState* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(GameState*);
extern "C" unsigned int ReadWordFieldAtOffset1C();
extern "C" void Object_ConfigureTextCountThroughEmbeddedHandler(void*, int);
extern "C" void func_020439b0(void*, int);
// Original: arm9/ov017 @ 0x021BEF4C; symbol: func_ov017_021bef4c; size: 0x38.
extern "C" void GameState_UpdateTextCountAndClearEmbeddedObject() {
    GameState* state = _ZN9GameState11GetInstanceEv();
    void* object = (void*)ReadWordFieldAtOffset1C();
    Object_ConfigureTextCountThroughEmbeddedHandler(object, (int)_ZNK9GameState12GetTickCountEv(state));
    func_020439b0(object, 0);
}
