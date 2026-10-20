#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*, int);
extern "C" int _ZNK8Object3D7GetFlagEi(void*, int);
extern "C" void _ZN8Object3D14AdvanceEffectsEv(void*);
// Original: arm9/ov017 @ 0x02197394; symbol: func_ov017_02197394; size: 0x54.
extern "C" void GameState_AdvanceUnflaggedObjectsA0ThroughBF(void) {
    void* state = _ZN9GameState11GetInstanceEv();
    for (int index = 0xa0; index < 0xc0; ++index) {
        void* object = _ZN9GameState20GetGameObjectByIndexEi(state, index);
        if (object != 0 && !_ZNK8Object3D7GetFlagEi(object, 0x40000000))
            _ZN8Object3D14AdvanceEffectsEv(object);
    }
}
