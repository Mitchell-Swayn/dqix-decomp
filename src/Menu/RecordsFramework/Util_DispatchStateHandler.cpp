#include <globaldefs.h>
ARM
class StateObject { public: int pad[7]; int state; typedef int (StateObject::*Handler)(int); };
struct Handlers { StateObject::Handler entries[4]; };
// Original data: arm9/ov023 @ 0x21fd984; symbol: data_ov023_021fd984.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 30bb1f020000000038bb1f020000000040bb1f02000000000000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" Handlers UtilDispatchStateHandler_UnknownRoleProcedureReferenceRecords;
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" StateObject::Handler ShopUpdateInterface_UnknownRoleInitializedBytes;
// Original: arm9/ov023 @ 0x021FBAB0; symbol: func_ov023_021fbab0; size: 0x80.
extern "C" void Util_DispatchStateHandler(StateObject *self, int arg) {
    Handlers handlers = UtilDispatchStateHandler_UnknownRoleProcedureReferenceRecords;
    handlers.entries[3] = ShopUpdateInterface_UnknownRoleInitializedBytes;
    self->state = (self->*handlers.entries[self->state])(arg);
}
