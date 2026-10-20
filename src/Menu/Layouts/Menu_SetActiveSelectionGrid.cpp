#include <globaldefs.h>
struct State { char pad[0x1b0]; unsigned short current; char pad2[0x16]; unsigned dirty; };
// Original: arm9/ov011 @ 0x021849E0; symbol: func_ov011_021849e0; size: 0x20.
extern "C" void Menu_SetActiveSelectionGrid(State* self, unsigned value) { if (self->current != value) self->dirty=1; self->current=value; }
