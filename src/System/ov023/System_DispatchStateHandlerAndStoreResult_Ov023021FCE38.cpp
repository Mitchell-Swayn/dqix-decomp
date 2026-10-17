#include <globaldefs.h>
ARM
struct State { char pad[0x1c]; int phase; };
typedef int (State::*Handler)(int);
struct Table { Handler handlers[4]; };
extern "C" { extern Table data_ov023_021fda14; extern Handler data_020e6d5c; }
// Original: arm9/ov023 @ 0x021FCE38; symbol: func_ov023_021fce38; size: 0x80.
extern "C" void System_DispatchStateHandlerAndStoreResult_Ov023021FCE38(State* p, int arg) {
 Table table=data_ov023_021fda14;
 table.handlers[3]=data_020e6d5c;
 p->phase=(p->*table.handlers[p->phase])(arg);
}
