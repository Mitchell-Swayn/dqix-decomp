#include <globaldefs.h>
ARM
class State { public: char pad[28]; int state; };
typedef int (State::*Handler)(int);
struct HandlerTable { Handler entries[4]; };
// Original data: arm9/ov023 @ 0x21fda34; symbol: data_ov023_021fda34.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex b8d21f0200000000f8d21f020000000018d31f02000000000000000000000000000000000000000000000000.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" HandlerTable MenuDisplayCommandDispatchRequestState_UnknownRoleProcedureReferenceRecords;
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Handler ShopUpdateInterface_UnknownRoleInitializedBytes;
// Original: arm9/ov023 @ 0x021FD238; symbol: func_ov023_021fd238; size: 0x80.
extern "C" void MenuDisplayCommand_DispatchRequestState(State *self, int value) {
    HandlerTable table = MenuDisplayCommandDispatchRequestState_UnknownRoleProcedureReferenceRecords;
    table.entries[3] = ShopUpdateInterface_UnknownRoleInitializedBytes;
    self->state = (self->*table.entries[self->state])(value);
}
