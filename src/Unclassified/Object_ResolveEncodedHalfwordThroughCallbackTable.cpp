#include <globaldefs.h>
ARM
typedef unsigned (*Convert)(unsigned);extern "C" Convert data_020f2adc[];
// Original: arm9/main @ 0x020DE194; symbol: func_020de194; size: 0x40.
extern "C" unsigned Object_ResolveEncodedHalfwordThroughCallbackTable(unsigned short* p){unsigned value=p[14];if(value>=0xfffb)value=data_020f2adc[0xffff-value](p[13]);return value;}
