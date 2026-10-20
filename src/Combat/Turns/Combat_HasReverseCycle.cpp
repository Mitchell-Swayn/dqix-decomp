#include <globaldefs.h>

// Original: arm9/ov000 @ 0x021598bc; symbol: func_ov000_021598bc; size: 0x18.
extern "C" ARM int Combat_HasReverseCycle(void* object) { unsigned char* p=(unsigned char*)object; return (*(unsigned int*)(*(unsigned int*)(p+0x138)+0x14) & 0x04000000) != 0; }
