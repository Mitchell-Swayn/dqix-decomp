#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned char CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
extern "C" void *Combat_GetDisplayRecordSlot(void *, int);
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void GameState_ClearObjectByIndex(void *, unsigned);
extern "C" void *Object_GetGlobalSixteenEntryDisplayState(void);
extern "C" unsigned char *ObjectPool_GetDisplayEntryByObjectIndex(unsigned char *, int);
extern "C" void ObjectPool_ResetDisplayEntry(unsigned char *);
// Original: arm9/ov025 @ 0x021E4FC8; symbol: func_ov025_021e4fc8; size: 0x4C.
extern "C" int ClearIndexedDisplayObjectAndEntry(unsigned char *object) {
    void *entry = Combat_GetDisplayRecordSlot(*(void **)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0xc), object[8]);
    if (entry != 0) {
        GameState_ClearObjectByIndex(_ZN9GameState11GetInstanceEv(), *(unsigned *)entry);
        unsigned char *state = (unsigned char *)Object_GetGlobalSixteenEntryDisplayState();
        unsigned char *record = ObjectPool_GetDisplayEntryByObjectIndex(state, *(unsigned *)entry);
        if (record != 0) ObjectPool_ResetDisplayEntry(record);
    }
    return 1;
}
