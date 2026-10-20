#include <globaldefs.h>
ARM

extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* Object_GetGlobalSixteenEntryDisplayState();
extern "C" int Combat_DispatchSelectionProcedure(void*, void*, int, int*);
extern "C" void* Combat_GetDisplayRecordSlot(void*, int);
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*, int);
extern "C" int GameState_InterpolateIndexedFixedValue(int, float, float);
extern "C" void _ZN8Object3D8SetScaleEiii(void*, int, int, int);
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned int CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov025 @ 0x021E8148; symbol: func_ov025_021e8148; size: 0xD4.
// Dispatch the selected combat procedure and apply its indexed display scale.
extern "C" int GameState_ApplySelectedCombatScale(void* self, void* first, void* unused, void* third)
{
    void* gameState = _ZN9GameState11GetInstanceEv();
    void* displayState = Object_GetGlobalSixteenEntryDisplayState();
    if (!gameState || !displayState)
        return 0;

    int selected[8];
    if (Combat_DispatchSelectionProcedure(third, first, *(int*)((char*)self + 8), selected) != 1)
        return 0;

    void* records = (void*)CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[3];
    int index = *(unsigned short*)((char*)self + 0x0c);
    int* entry = (int*)Combat_GetDisplayRecordSlot(records, index);
    if (!entry)
        return 0;

    void* object = _ZN9GameState20GetGameObjectByIndexEi(gameState, *entry);
    if (!object)
        return 0;

    int mode = *(unsigned char*)((char*)self + 0x0e);
    int scale = 0x10a;
    if (mode != 0) {
        if (mode == 1)
            scale = GameState_InterpolateIndexedFixedValue(selected[0], 1.0f, 0.5f);
    }
    _ZN8Object3D8SetScaleEiii(object, scale, scale, scale);
    return 1;
}
