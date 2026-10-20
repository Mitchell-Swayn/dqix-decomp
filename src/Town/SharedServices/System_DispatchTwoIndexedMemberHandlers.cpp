#include <globaldefs.h>
ARM
struct DispatchOwner { unsigned char pad[0xec]; unsigned char first,second; };
typedef void (DispatchOwner::*Handler)();
struct SevenHandlers { Handler handlers[7]; };
struct HandlerTable { SevenHandlers block; Handler last; };
extern "C" {
void* _ZN9GameState11GetInstanceEv();
unsigned _ZNK9GameState12GetTickCountEv(void*);
// Original data: arm9/ov003 @ 0x217fa20; symbol: data_ov003_0217fa20.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex fc28170200000000142a170200000000842e170200000000cc33170200000000d03317020000000090341702000000000000000000000000.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
// Original data: arm9/ov003 @ 0x217fa58; symbol: data_ov003_0217fa58.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 0835170200000000c4351702000000008837170200000000e437170200000000f43a170200000000483b1702000000000000000000000000.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern SevenHandlers SystemDispatchTwoIndexedMemberHandlers_UnknownRoleProcedureReferenceRecords,SystemDispatchTwoIndexedMemberHandlers_UnknownRoleProcedureReferenceRecords_Variant2;
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Handler ShopUpdateInterface_UnknownRoleInitializedBytes;
}
// Original: arm9/ov003 @ 0x021727C8; symbol: func_ov003_021727c8; size: 0x134.
extern "C" int System_DispatchTwoIndexedMemberHandlers(DispatchOwner* p) {
_ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());
int first=0,second=0;
SevenHandlers a=SystemDispatchTwoIndexedMemberHandlers_UnknownRoleProcedureReferenceRecords;
a.handlers[6]=ShopUpdateInterface_UnknownRoleInitializedBytes;
SevenHandlers b=SystemDispatchTwoIndexedMemberHandlers_UnknownRoleProcedureReferenceRecords_Variant2;
b.handlers[6]=ShopUpdateInterface_UnknownRoleInitializedBytes;
if(a.handlers[p->first]) (p->*a.handlers[p->first])(); else first=1;
if(b.handlers[p->second]) (p->*b.handlers[p->second])(); else second=1;
if(first&&second) return 0;
return 1;
}
