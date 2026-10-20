#include <globaldefs.h>
struct FlagBits { unsigned char unused : 1; unsigned char value : 1; };
// Original: arm9/ov024 @ 0x021F0D0C; symbol: func_ov024_021f0d0c; size: 0x1C.
extern "C" unsigned int GameState_IsNestedFlagBit1Set(void* p) { void* q = *(void**)((char*)p + 0x138); return ((struct FlagBits*)((char*)q + 0x3c))->value != 0; }
