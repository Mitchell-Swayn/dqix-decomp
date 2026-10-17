#include <globaldefs.h>
ARM
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void**, unsigned short);
// Original: arm9/ov023 @ 0x021F65D4; symbol: func_ov023_021f65d4; size: 0x2C.
extern "C" void* GameState_AppendValueAndSetNodeFlags(void* unused, unsigned short value, unsigned int flags) { void** head = (void**)func_ov011_021849c8(unused); void* node = func_ov023_021f6880(head, value); if (node) *((unsigned char*)node + 0xc) |= flags; return node; }
