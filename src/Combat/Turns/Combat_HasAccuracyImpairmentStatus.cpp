#include <globaldefs.h>

// Original: arm9/ov000 @ 0x02156b20; symbol: func_ov000_02156b20; size: 0x18.
extern "C" ARM int Combat_HasAccuracyImpairmentStatus(void* object) { unsigned char* p=(unsigned char*)object; return (*(unsigned int*)(*(unsigned int*)(p+0x138)+0x14) & 0x40) != 0; }
