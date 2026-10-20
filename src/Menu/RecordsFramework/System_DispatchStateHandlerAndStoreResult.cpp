#include <globaldefs.h>
ARM
struct State { char pad[0x1c]; int phase; };
typedef int (State::*Handler)(int);
struct Table { Handler handlers[4]; };
// Original data: arm9/ov023 @ 0x21fd944; symbol: data_ov023_021fd944.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex fca81f0200000000a4a91f020000000050aa1f02000000000000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" { extern Table SystemDispatchStateHandlerAndStoreResult_UnknownRoleProcedureReferenceRecords; extern Handler ShopUpdateInterface_UnknownRoleInitializedBytes; }
// Original: arm9/ov023 @ 0x021FA87C; symbol: func_ov023_021fa87c; size: 0x80.
extern "C" void System_DispatchStateHandlerAndStoreResult(State* p, int arg) {
 Table table=SystemDispatchStateHandlerAndStoreResult_UnknownRoleProcedureReferenceRecords;
 table.handlers[3]=ShopUpdateInterface_UnknownRoleInitializedBytes;
 p->phase=(p->*table.handlers[p->phase])(arg);
}
