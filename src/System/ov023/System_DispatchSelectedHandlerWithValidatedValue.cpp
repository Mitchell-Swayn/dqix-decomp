#include <globaldefs.h>
ARM
struct State { unsigned char pad[0x5d4]; int first; unsigned unknown; int second; unsigned char pad2[0x10]; int selection; };
typedef void (State::*Handler)();
struct Table { Handler handlers[3]; };
extern "C" Table data_ov023_021fd7b4;
// Original: arm9/ov023 @ 0x021E7C58; symbol: func_ov023_021e7c58; size: 0x94.
extern "C" void System_DispatchSelectedHandlerWithValidatedValue(State* p,int handler,int selection) {
 if(p->first && p->second) {
  int valid=(selection>=0 && selection<=3);
  if(valid) {
   p->selection=selection;
   Table table=data_ov023_021fd7b4;
   (p->*table.handlers[handler])();
  }
 }
}
