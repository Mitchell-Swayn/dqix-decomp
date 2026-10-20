#include <globaldefs.h>
ARM
struct State { unsigned char pad[0x5d4]; int first; unsigned unknown; int second; unsigned char pad2[0x10]; int selection; };
typedef void (State::*Handler)();
struct Table { Handler handlers[3]; };
// Original data: arm9/ov023 @ 0x21fd7b4; symbol: data_ov023_021fd7b4.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex b07e1e0200000000e47f1e0200000000f4811e0200000000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" Table SystemDispatchSelectedHandlerWithValidatedValue_UnknownRoleProcedureReferenceRecords;
// Original: arm9/ov023 @ 0x021E7C58; symbol: func_ov023_021e7c58; size: 0x94.
extern "C" void System_DispatchSelectedHandlerWithValidatedValue(State* p,int handler,int selection) {
 if(p->first && p->second) {
  int valid=(selection>=0 && selection<=3);
  if(valid) {
   p->selection=selection;
   Table table=SystemDispatchSelectedHandlerWithValidatedValue_UnknownRoleProcedureReferenceRecords;
   (p->*table.handlers[handler])();
  }
 }
}
