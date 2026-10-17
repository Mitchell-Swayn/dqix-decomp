#include <globaldefs.h>

// Original: arm9/ov000 @ 0x02156af0; symbol: func_ov000_02156af0; size: 0x18.
extern "C" ARM int TestNestedField18Bit800(void* object) { unsigned char* p=(unsigned char*)object; return (*(unsigned int*)(*(unsigned int*)(p+0x138)+0x18) & 0x800) != 0; }
