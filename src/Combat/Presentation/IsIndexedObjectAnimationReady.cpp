#include <globaldefs.h>
ARM
extern "C" void* Combat_GetCommandActorSnapshot(int, int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*, int);
extern "C" int _ZNK8Object3D19HasAnimationStoppedEv(void*);
extern "C" int _ZNK8Object3D15GetOffset40Bit1Ev(void*);
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned int CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov025 @ 0x021E2C34; symbol: IsIndexedObjectAnimationReady; size: 0x70.
// Resolves the indexed object, rejects when global flag bit 2 is set, then checks animation stopped or Object3D offset bit 1.
extern "C" int IsIndexedObjectAnimationReady(void* unused, int index) {
    void* record = Combat_GetCommandActorSnapshot(index, 0);
    if (record == 0) return 0;
    unsigned short objectIndex = *(unsigned short*)((char*)record + 0x20);
    void* game = _ZN9GameState11GetInstanceEv();
    void* object = _ZN9GameState20GetGameObjectByIndexEi(game, objectIndex);
    if (*((unsigned int*)((char*)&CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0x1C)) & 4) return 0;
    if (_ZNK8Object3D19HasAnimationStoppedEv(object)) return 1;
    return _ZNK8Object3D15GetOffset40Bit1Ev(object) != 0;
}
