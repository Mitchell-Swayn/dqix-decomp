#include <globaldefs.h>
ARM
class State { public: char pad[28]; int state; };
typedef int (State::*Handler)(int);
struct HandlerTable { Handler entries[4]; };
extern "C" HandlerTable data_ov023_021fda34;
extern "C" Handler data_020e6d5c;
// Original: arm9/ov023 @ 0x021FD238; symbol: func_ov023_021fd238; size: 0x80.
extern "C" void DispatchStateHandler021FD238(State *self, int value) {
    HandlerTable table = data_ov023_021fda34;
    table.entries[3] = data_020e6d5c;
    self->state = (self->*table.entries[self->state])(value);
}
