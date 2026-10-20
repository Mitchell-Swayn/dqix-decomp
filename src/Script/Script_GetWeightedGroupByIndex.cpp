#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0209B9C0; symbol: func_0209b9c0; size: 0x24.
extern "C" unsigned char* Script_GetWeightedGroupByIndex(unsigned char* p,int i) { if (i<0 || i>=6) return 0; return p+i*76; }
