#include <globaldefs.h>

// Original: arm9/main @ 0x02033F44; symbol: func_02033f44; size: 0x18.
extern "C" ARM int Object_GetOffsetE4RecordWhenBit6Set (int p) { return (((unsigned int)*(unsigned char*)(p+0xe0) << 25) >> 31) ? p+0xe4 : 0; }
