#include <globaldefs.h>
ARM
struct State { char pad[28]; int phase; };
typedef int (State::*Handler)(int);
struct Table { Handler handlers[4]; };
// Original data: arm9/ov023 @ 0x21fd8fc; symbol: data_ov023_021fd8fc.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex d0751f020000000088761f020000000084771f02000000000000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" { extern Table DispatchIndexedMemberAndUpdateState_UnknownRoleProcedureReferenceRecords; extern Handler ShopUpdateInterface_UnknownRoleInitializedBytes; }
// Original: arm9/ov023 @ 0x021F7550; symbol: func_ov023_021f7550; size: 0x80.
extern "C" void DispatchIndexedMemberAndUpdateState(State* p,int arg) { Table local=DispatchIndexedMemberAndUpdateState_UnknownRoleProcedureReferenceRecords; local.handlers[3]=ShopUpdateInterface_UnknownRoleInitializedBytes; p->phase=(p->*local.handlers[p->phase])(arg); }
