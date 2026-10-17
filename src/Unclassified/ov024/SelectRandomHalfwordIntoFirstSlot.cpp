#include <globaldefs.h>
extern "C" int _Z13NextRandomMaxP6Randomi(void*,int);
// Original: arm9/ov024 @ 0x021ED890; symbol: func_ov024_021ed890; size: 0x30.
extern "C" ARM int SelectRandomHalfwordIntoFirstSlot(void** random, int* count, short* values) { int index=_Z13NextRandomMaxP6Randomi(*random,*count); values[0]=values[index]; *count=1; return 1; }
