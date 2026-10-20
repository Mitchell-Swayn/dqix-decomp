#include <globaldefs.h>
struct A{char pad[0x3f];unsigned char bit:1;};
// Original: arm9/main @ 0x020E28DC; symbol: func_020e28dc; size: 0x14.
extern "C" unsigned int Window_IsVisible(A **p){return p[3]->bit;}
