#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
int Grid_ComputeSelectedLinearIndex(unsigned char *);
// Original: arm9/main @ 0x0205BD04; symbol: func_0205bd04; size: 0x1C.
int Grid_ReadLinearIndexWhenEnabled(unsigned char *p){if(!p[0x4e])return -1;return Grid_ComputeSelectedLinearIndex(p);}
}
