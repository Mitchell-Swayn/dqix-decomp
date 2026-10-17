#include <globaldefs.h>
ARM
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void**, unsigned short);
// Original: arm9/ov004 @ 0x0215E47C; symbol: func_ov004_0215e47c; size: 0x20.
extern "C" void* func_ov004_0215e47c(void* self, unsigned short value) { void** head = (void**)func_ov011_021849c8(self); void* result = func_ov023_021f6880(head, value); if (!result) result = 0; return result; }
