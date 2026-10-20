#include <globaldefs.h>
struct PackedNibble { unsigned char value : 4; };
// Original: arm9/ov001 @ 0x021612AC; symbol: func_ov001_021612ac; size: 0x1C.
extern "C" unsigned int GameObject_ReadLinkedStatusLowNibble(void* p) { struct PackedNibble* q = (struct PackedNibble*)(*(void**)((char*)p + 0x150)); if (!q) return 0; return q[0x56b].value; }
