#include <globaldefs.h>
ARM
struct State { char pad[28]; int phase; };
typedef int (State::*Handler)(int);
struct Table { Handler handlers[4]; };
extern "C" { extern Table data_ov023_021fd9a4; extern Handler data_020e6d5c; }
// Original: arm9/ov023 @ 0x021FBE70; symbol: func_ov023_021fbe70; size: 0x80.
extern "C" void DispatchIndexedMemberAndUpdateState_Ov023021FBE70(State* p,int arg) { Table local=data_ov023_021fd9a4; local.handlers[3]=data_020e6d5c; p->phase=(p->*local.handlers[p->phase])(arg); }
