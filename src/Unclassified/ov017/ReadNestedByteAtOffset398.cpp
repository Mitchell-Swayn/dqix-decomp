#include <globaldefs.h>
ARM
// Returns byte 0x398 of the pointer stored at receiver offset 0x24, or zero when that pointer is null.
// Original: arm9/ov017 @ 0x021b2010; symbol: func_ov017_021b2010; size: 0x14.
extern "C" ARM unsigned int ReadNestedByteAtOffset398(void* self) { void* nested = *(void**)((unsigned char*)self + 0x24); return nested ? *((unsigned char*)nested + 0x398) : 0; }
