#include <globaldefs.h>
// Original: arm9/ov000 @ 0x02156cac; symbol: func_ov000_02156cac; size: 0x18.
extern "C" int Combat_HasIncreasedStatusSusceptibility(void* object) { unsigned int flags=*(unsigned int*)(*(char**)((char*)object+0x138)+0x18); return (flags&0x10)!=0; }
