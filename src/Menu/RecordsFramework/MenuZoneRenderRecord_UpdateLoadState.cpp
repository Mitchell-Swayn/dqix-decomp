#include <globaldefs.h>
ARM
struct Object { char pad[0x1c]; int state; };
typedef int(Object::*Handler)(int);
struct Table { Handler entries[4]; };
// Original data: arm9/ov023 @ 0x21fd8d8; symbol: data_ov023_021fd8d8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 10701f02000000007c701f020000000028711f0200000000000000000000000000001000.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" Table MenuZoneRenderRecordUpdateLoadState_UnknownRoleProcedureReferenceRecords;
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Handler ShopUpdateInterface_UnknownRoleInitializedBytes;
// Original: arm9/ov023 @ 0x021F6F90; symbol: func_ov023_021f6f90; size: 0x80.
extern "C" void MenuZoneRenderRecord_UpdateLoadState(Object* p,int arg) {
Table local=MenuZoneRenderRecordUpdateLoadState_UnknownRoleProcedureReferenceRecords;
local.entries[3]=ShopUpdateInterface_UnknownRoleInitializedBytes;
p->state=(p->*local.entries[p->state])(arg);
}
