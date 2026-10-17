#include <globaldefs.h>
ARM
class StateObject { public: int pad[7]; int state; typedef int (StateObject::*Handler)(int); };
struct Handlers { StateObject::Handler entries[4]; };
extern "C" Handlers data_ov023_021fd984;
extern "C" StateObject::Handler data_020e6d5c;
// Original: arm9/ov023 @ 0x021FBAB0; symbol: func_ov023_021fbab0; size: 0x80.
extern "C" void Util_DispatchStateHandler(StateObject *self, int arg) {
    Handlers handlers = data_ov023_021fd984;
    handlers.entries[3] = data_020e6d5c;
    self->state = (self->*handlers.entries[self->state])(arg);
}
