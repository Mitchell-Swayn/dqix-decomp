#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*, int);
extern "C" void GameState_ClearObjectByIndex(void*, unsigned);
extern "C" void _ZN8Object3D6DetachEv(void*);
extern "C" void _ZN8Object3D11MakeVisibleEv(void*);
// Original: arm9/ov025 @ 0x021E7470; symbol: func_ov025_021e7470; size: 0x60.
extern "C" int GameState_ReplaceTemporaryObjectAndRevealIndexed(void* unused, unsigned char* data) {
    void* state = _ZN9GameState11GetInstanceEv();
    void* old = _ZN9GameState20GetGameObjectByIndexEi(state, 0xc8);
    if (old) {
        _ZN8Object3D6DetachEv(old);
        GameState_ClearObjectByIndex(state, 0xc8);
    }
    unsigned short id = *(unsigned short*)((char*)*(void**)(data + 0x10) + 0x20);
    void* target = _ZN9GameState20GetGameObjectByIndexEi(state, id * 12 + 0x1c);
    if (target) _ZN8Object3D11MakeVisibleEv(target);
    return 1;
}
