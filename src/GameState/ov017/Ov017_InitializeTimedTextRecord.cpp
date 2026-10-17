#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned int ReadWordFieldAtOffset1C(void*);
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void*);
extern "C" void Object_ConfigureTextCountThroughEmbeddedHandler(void*, int);
extern "C" void func_020439b0(void*, int);
extern "C" void IgnoreEmbeddedOwnerState(void*);
// Original: arm9/ov017 @ 0x021A79AC; symbol: func_ov017_021a79ac; size: 0x44.
extern "C" ARM void Ov017_InitializeTimedTextRecord(void* object) {
    void* state = _ZN9GameState11GetInstanceEv();
    unsigned int record = ReadWordFieldAtOffset1C(state);
    unsigned tick = _ZNK9GameState12GetTickCountEv(state);
    Object_ConfigureTextCountThroughEmbeddedHandler((void*)record, tick);
    func_020439b0((void*)record, 0);
    IgnoreEmbeddedOwnerState((char*)object + 0x24);
}
