#include <globaldefs.h>
ARM
class State { public: char pad[28]; int state; };
typedef int (State::*Handler)(int);
struct HandlerTable { Handler entries[4]; };
// Original data: arm9/ov023 @ 0x21fd964; symbol: data_ov023_021fd964.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 00b71f02000000006cb71f020000000018b81f02000000000000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" HandlerTable MenuSpriteDispatchLoadAndDrawState_UnknownRoleProcedureReferenceRecords;
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Handler ShopUpdateInterface_UnknownRoleInitializedBytes;
// Original: arm9/ov023 @ 0x021FB680; symbol: func_ov023_021fb680; size: 0x80.
extern "C" void MenuSprite_DispatchLoadAndDrawState(State *self, int value) {
    HandlerTable table = MenuSpriteDispatchLoadAndDrawState_UnknownRoleProcedureReferenceRecords;
    table.entries[3] = ShopUpdateInterface_UnknownRoleInitializedBytes;
    self->state = (self->*table.entries[self->state])(value);
}
