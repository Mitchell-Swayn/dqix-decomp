#include <globaldefs.h>
struct Bits { unsigned char b0:1; unsigned char rest:7; };
// Original: arm9/main @ 0x02011B24; symbol: func_02011b24; size: 0x18.
extern "C" ARM void Object_ResetByte63DCToBit0(char* p) { *(unsigned char*)(p+0x63dc)=0; ((Bits*)(p+0x63dc))->b0=1; }
