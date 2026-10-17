#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0209C08C; symbol: func_0209c08c; size: 0x1C.
extern "C" void Object_AppendHalfwordWithinTwelveEntryLimit(unsigned short* p,unsigned short value) { unsigned short count=p[12]; if (count<12) { p[12]=count+1; p[count]=value; } }
