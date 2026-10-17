#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameResources_GetInstance();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*, int);
extern "C" void func_ov017_0218f5a4(void*, int, int, int, int);
extern "C" int ReadMaskedWord(void*, unsigned);
// Original: arm9/ov017 @ 0x021B0B4C; symbol: func_ov017_021b0b4c; size: 0x74.
extern "C" int ProcessExistingGameObjects() {
    void* gameState = _ZN9GameState11GetInstanceEv();
    void* resources = GameResources_GetInstance();
    for (int i = 0; i < 4; ++i) {
        if (_ZN9GameState20GetGameObjectByIndexEi(gameState, i) != 0)
            func_ov017_0218f5a4(resources, i, 0, 0, 0);
    }
    return ReadMaskedWord(resources, 0x10) == 0;
}
