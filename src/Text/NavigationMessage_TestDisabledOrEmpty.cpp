#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
struct A{char pad[0x3c9];unsigned char enabled:1;char pad2;signed char state;};
// Original: arm9/main @ 0x0209494C; symbol: func_0209494c; size: 0x30.
bool NavigationMessage_TestDisabledOrEmpty(A *p){if(p->enabled)return p->state<=0;return true;}
}
