#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02087FF0; symbol: func_02087ff0; size: 0x28.
extern "C" void ClearField14Flag2000000AndField58Flag38000000AndBytes77And9A(unsigned char* p) { *(unsigned int*)(p+0x14)&=~0x2000000; *(unsigned int*)(p+0x58)&=~0x38000000;p[0x77]=0;p[0x9a]=0; }
