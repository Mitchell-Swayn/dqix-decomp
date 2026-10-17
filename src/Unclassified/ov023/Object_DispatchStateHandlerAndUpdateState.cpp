#include <globaldefs.h>
ARM
struct Object { char pad[0x1c]; int state; };
typedef int(Object::*Handler)(int);
struct Table { Handler entries[4]; };
extern "C" Table data_ov023_021fd8d8;
extern "C" Handler data_020e6d5c;
// Original: arm9/ov023 @ 0x021F6F90; symbol: func_ov023_021f6f90; size: 0x80.
extern "C" void Object_DispatchStateHandlerAndUpdateState(Object* p,int arg) {
Table local=data_ov023_021fd8d8;
local.entries[3]=data_020e6d5c;
p->state=(p->*local.entries[p->state])(arg);
}
