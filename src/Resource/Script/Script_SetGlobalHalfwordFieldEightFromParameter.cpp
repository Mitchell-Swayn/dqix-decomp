#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
int _ZNK6Script9Parameter5ToIntEv(void *);extern char *data_02108efc;
// Original: arm9/main @ 0x020899BC; symbol: func_020899bc; size: 0x20.
bool Script_SetGlobalHalfwordFieldEightFromParameter(void *p){int v=_ZNK6Script9Parameter5ToIntEv(p);*(short *)(data_02108efc+8)=v;return true;}
}
