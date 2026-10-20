#include <globaldefs.h>
ARM
struct Object { char pad[0x1c]; int state; };
typedef int(Object::*Handler)(int);
struct Table { Handler entries[4]; };
// Original data: arm9/ov023 @ 0x21fd9c4; symbol: data_ov023_021fd9c4.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex b8c21f02000000000cc31f0200000000f8c31f02000000000000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" Table MenuScriptDispatchResourceExecutionState_UnknownRoleProcedureReferenceRecords;
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Handler ShopUpdateInterface_UnknownRoleInitializedBytes;
// Original: arm9/ov023 @ 0x021FC238; symbol: func_ov023_021fc238; size: 0x80.
extern "C" void MenuScript_DispatchResourceExecutionState(Object* p,int arg) {
Table local=MenuScriptDispatchResourceExecutionState_UnknownRoleProcedureReferenceRecords;
local.entries[3]=ShopUpdateInterface_UnknownRoleInitializedBytes;
p->state=(p->*local.entries[p->state])(arg);
}
