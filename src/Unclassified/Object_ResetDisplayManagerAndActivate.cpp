#include <globaldefs.h>
ARM
extern "C" void Object_InitializeSixteenDisplayRecordsAndFlags(void*);
struct State {char pad[0x3c9];unsigned char active:1;unsigned char rest:7;};
// Original: arm9/main @ 0x020939DC; symbol: func_020939dc; size: 0x20.
extern "C" void Object_ResetDisplayManagerAndActivate(State* p) {
    Object_InitializeSixteenDisplayRecordsAndFlags(p);
    p->active=1;
}
