#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x02067A9C; symbol: func_02067a9c; size: 0x3C.
int Text_IsHalfwordControlCodeFF01ThroughFF0D(int unused,void *p){unsigned short v;memcpy(&v,p,2);if(v>=0xff01&&v<=0xff0d)return 1;return 0;}
}
