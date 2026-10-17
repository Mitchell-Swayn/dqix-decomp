#include <globaldefs.h>
// Original: arm9/ov000 @ 0x0215988c; symbol: func_ov000_0215988c; size: 0x18.
extern "C" int HasNestedFlag28(void* object) { unsigned int flags=*(unsigned int*)(*(char**)((char*)object+0x138)+0x14); return (flags&0x10000000)!=0; }
