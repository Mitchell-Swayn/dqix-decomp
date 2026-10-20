#include <globaldefs.h>
ARM
extern "C" void NavigationMessage_InitializeQueuesAndDisplayState(void*);
struct State {char pad[0x3c9];unsigned char active:1;unsigned char rest:7;};
// Original: arm9/main @ 0x020939DC; symbol: func_020939dc; size: 0x20.
extern "C" void NavigationMessage_ResetAndEnable(State* p) {
    NavigationMessage_InitializeQueuesAndDisplayState(p);
    p->active=1;
}
