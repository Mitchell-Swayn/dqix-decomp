#include <globaldefs.h>
extern "C" {
struct A{unsigned int rest:24;unsigned int value:2;};
// Original: arm9/main @ 0x020688B0; symbol: func_020688b0; size: 0x1C.
unsigned int ReadIndirectIndex4ValueOrZero(int unused,A **p){A *q=p[4];if(q)return q[2].value;return 0;}
}
