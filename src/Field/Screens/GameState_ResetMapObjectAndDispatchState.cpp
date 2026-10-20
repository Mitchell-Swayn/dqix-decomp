#include <globaldefs.h>
ARM
struct MapGameObject; struct Object;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" MapGameObject* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void GameObject_DisableMovementInput(Object *p,int reset);
class StateObject { public: int a,b,state; typedef int (StateObject::*Handler)(); };
// Original data: arm9/ov017 @ 0x21d83f0; symbol: data_ov017_021d83f0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned ResourceGetSharedLoadState_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" StateObject::Handler ShopUpdateInterface_UnknownRoleInitializedBytes;
// Original data: arm9/ov017 @ 0x21d79e0; symbol: data_ov017_021d79e0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 88231b0200000000d0241b020000000098261b020000000058271b020000000068291b0200000000d82a1b0200000000142b1b0200000000682b1b0200000000 ...; full span in module reference.
// Observed span: 72 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" StateObject::Handler GameStateResetMapObjectAndDispatchState_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/ov017 @ 0x021B228C; symbol: func_ov017_021b228c; size: 0x9C.
extern "C" void GameState_ResetMapObjectAndDispatchState(StateObject *self) {
    MapGameObject *object = _ZN9GameState20GetUnknownGameObjectEv(_ZN9GameState11GetInstanceEv());
    if (object) GameObject_DisableMovementInput((Object*)object, 1);
    if (!(ResourceGetSharedLoadState_UnknownRoleZeroInitializedStorage & 1)) {
        GameStateResetMapObjectAndDispatchState_UnknownRoleProcedureReferenceRecords[8] = ShopUpdateInterface_UnknownRoleInitializedBytes;
        ResourceGetSharedLoadState_UnknownRoleZeroInitializedStorage |= 1;
    }
    if (GameStateResetMapObjectAndDispatchState_UnknownRoleProcedureReferenceRecords[self->state])
        self->state = (self->*GameStateResetMapObjectAndDispatchState_UnknownRoleProcedureReferenceRecords[self->state])();
}
