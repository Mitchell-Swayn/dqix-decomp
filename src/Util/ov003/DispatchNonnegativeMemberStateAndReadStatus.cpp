#include <globaldefs.h>
ARM
struct State { char pad[0x140]; signed char phase; char pad2[2]; unsigned char status; };
typedef void (State::*Handler)();
struct Table { Handler handlers[6]; };
extern "C" { extern Table data_ov003_0217fb98; extern Handler data_020e6d5c; }
// Original: arm9/ov003 @ 0x0217BDB8; symbol: func_ov003_0217bdb8; size: 0x88.
extern "C" unsigned char DispatchNonnegativeMemberStateAndReadStatus(State* p) { Table local=data_ov003_0217fb98; local.handlers[5]=data_020e6d5c; if(p->phase>=0)(p->*local.handlers[p->phase])(); return p->status; }
