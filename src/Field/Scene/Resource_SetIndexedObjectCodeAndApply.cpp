#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameResources_GetInstance();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*, int);
extern "C" void Resource_ApplyUpdateOnlyWhenValidationPasses(void*, unsigned);
// Original: arm9/ov017 @ 0x021BDB78; symbol: func_ov017_021bdb78; size: 0x48.
extern "C" void Resource_SetIndexedObjectCodeAndApply(int index) {
    void* game = _ZN9GameState11GetInstanceEv();
    void* resources = GameResources_GetInstance();
    void* object = _ZN9GameState20GetGameObjectByIndexEi(game, index);
    if (!object) return;
    *(unsigned short*)((char*)object + 0x9c) = 0x40c8;
    Resource_ApplyUpdateOnlyWhenValidationPasses(resources, 0);
}
