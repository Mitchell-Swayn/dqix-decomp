#include <globaldefs.h>
ARM
struct Object { unsigned char pad[0x776]; unsigned char state; };
typedef void (Object::*Callback)();
struct InitFlags { unsigned pad[7]; unsigned flags; };
struct CallbackOwner { unsigned char pad[0x40]; Callback callback; };
// Original data: arm9/ov023 @ 0x21ffa0c; symbol: data_ov023_021ffa0c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" unsigned char ItemDetailDispatchDisplayState_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov023 @ 0x21ff9e0; symbol: data_ov023_021ff9e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" InitFlags MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Callback ShopUpdateInterface_UnknownRoleInitializedBytes;
extern "C" CallbackOwner ItemDetail_DispatchDisplayState_TextLia;
// Original data: arm9/ov023 @ 0x21fda88; symbol: data_ov023_021fda88.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 9cd51d020000000074d91d020000000004da1d02000000000000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" Callback ItemDetailDispatchDisplayState_UnknownRoleProcedureReferenceRecords[];
extern "C" void Util_UpdateRandomPointTimers(void*);
// Original: arm9/ov023 @ 0x021DC488; symbol: func_ov023_021dc488; size: 0x98.
extern "C" int ItemDetail_DispatchDisplayState(Object* self) {
 Util_UpdateRandomPointTimers(ItemDetailDispatchDisplayState_UnknownRoleZeroInitializedStorage);
 if(!(MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage.flags&1)) {
  ItemDetail_DispatchDisplayState_TextLia.callback=ShopUpdateInterface_UnknownRoleInitializedBytes;
  MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage.flags|=1;
 }
 if(ItemDetailDispatchDisplayState_UnknownRoleProcedureReferenceRecords[self->state]==0) return 1;
 (self->*ItemDetailDispatchDisplayState_UnknownRoleProcedureReferenceRecords[self->state])();
 return 0;
}
