#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021D8DDC; symbol: RebuildIndexedValueCacheAndSetReadinessFlags; size: 0x70.
// Rebuilds the indexed value cache and updates the readiness bytes.
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* memset(void*, int, unsigned);
extern "C" unsigned Window_GetCanvasStackDepth(char*);
extern "C" void PartyGrowthPanel_SetExperienceAwards(unsigned char* object, unsigned* values) {
    _ZN9GameState11GetInstanceEv();
    unsigned char* indices = object + 0x124;
    int count = object[0x128];
    memset(object + 0xdc, 0, 0x10);
    for (int i = 0; i < count; ++i) {
        unsigned index = indices[i];
        *(unsigned*)(object + 0xdc + i * 4) = values[index];
    }
    if (!Window_GetCanvasStackDepth((char*)object + 0x20)) object[0x11c] = 0; else object[0x11c] = 1;
    object[0x11a] = 1;
}
