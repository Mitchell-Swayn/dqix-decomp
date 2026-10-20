#include <globaldefs.h>
ARM
struct State { char pad[0x140]; signed char phase; char pad2[2]; unsigned char status; };
typedef void (State::*Handler)();
struct Table { Handler handlers[6]; };
// Original data: arm9/ov003 @ 0x217fb98; symbol: data_ov003_0217fb98.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 40be17020000000078bf170200000000bcc21702000000004cc7170200000000a0c71702000000000000000000000000.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" { extern Table DispatchNonnegativeMemberStateAndReadStatus_UnknownRoleProcedureReferenceRecords; extern Handler ShopUpdateInterface_UnknownRoleInitializedBytes; }
// Original: arm9/ov003 @ 0x0217BDB8; symbol: func_ov003_0217bdb8; size: 0x88.
extern "C" unsigned char DispatchNonnegativeMemberStateAndReadStatus(State* p) { Table local=DispatchNonnegativeMemberStateAndReadStatus_UnknownRoleProcedureReferenceRecords; local.handlers[5]=ShopUpdateInterface_UnknownRoleInitializedBytes; if(p->phase>=0)(p->*local.handlers[p->phase])(); return p->status; }
