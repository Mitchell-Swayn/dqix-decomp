#include <globaldefs.h>
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void *);
extern "C" unsigned ReadWordFieldAtOffset1C();
extern "C" void Object_ConfigureTextCountThroughEmbeddedHandler(void *, int);
extern "C" void func_020439b0(void *, int);
extern "C" void ResetEachIndexedEntryResource(void *);
// Original: arm9/ov003 @ 0x02170280; symbol: func_ov003_02170280; size: 0x64.
extern "C" void OV003_RefreshTimedEntryResources(void *owner) {
    if (!*(void **)((char *)owner + 0x3c)) return;
    if (*(signed char *)((char *)owner + 1) <= 1) return;
    void *game = _ZN9GameState11GetInstanceEv();
    void *shared = (void *)ReadWordFieldAtOffset1C();
    Object_ConfigureTextCountThroughEmbeddedHandler(shared, _ZNK9GameState12GetTickCountEv(game));
    func_020439b0(shared, 0);
    if (*(void **)((char *)owner + 0x3c)) ResetEachIndexedEntryResource(*(void **)((char *)owner + 0x3c));
}
