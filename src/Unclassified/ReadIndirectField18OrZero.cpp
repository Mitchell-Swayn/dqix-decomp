#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020416CC; symbol: func_020416cc; size: 0x14.
extern "C" unsigned int ReadIndirectField18OrZero(unsigned char* p) { unsigned int* v=*(unsigned int**)(p+0x18); return v ? *v : 0; }
