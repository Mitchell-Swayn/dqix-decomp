#pragma opt_strength_reduction off
#include <globaldefs.h>
extern "C" double _dsqrt(double);
// Original: arm9/main @ 0x02012798; symbol: func_02012798; size: 0x34.
extern "C" ARM int TouchInput_ComputeSampleDistance(char* object){int x=*(int*)(object+56)-*(unsigned short*)(object+32);int y=*(int*)(object+60)-*(unsigned short*)(object+34);return (int)_dsqrt((double)(x*x+y*y));}
