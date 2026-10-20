#include <globaldefs.h>
ARM
struct State { char pad[28]; int phase; };
typedef int (State::*Handler)(int);
struct Table { Handler handlers[4]; };
// Original data: arm9/ov023 @ 0x21fd9a4; symbol: data_ov023_021fd9a4.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex f0be1f02000000004cbf1f0200000000e4c11f02000000000000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" { extern Table MenuZoneDispatchResourceLoadState_UnknownRoleProcedureReferenceRecords; extern Handler ShopUpdateInterface_UnknownRoleInitializedBytes; }
// Original: arm9/ov023 @ 0x021FBE70; symbol: func_ov023_021fbe70; size: 0x80.
extern "C" void MenuZone_DispatchResourceLoadState(State* p,int arg) { Table local=MenuZoneDispatchResourceLoadState_UnknownRoleProcedureReferenceRecords; local.handlers[3]=ShopUpdateInterface_UnknownRoleInitializedBytes; p->phase=(p->*local.handlers[p->phase])(arg); }
