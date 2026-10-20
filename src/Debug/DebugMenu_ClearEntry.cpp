#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x0202949C; symbol: func_0202949c; size: 0x30.
void DebugMenu_ClearEntry(unsigned int *p){*(char *)(p+1)=0;memset(p+1,0,48);p[0]=0;p[13]=0;p[14]=0;}
}
