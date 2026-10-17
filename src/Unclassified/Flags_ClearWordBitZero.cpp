#include <globaldefs.h>
// func_02040648: 0x02040648–0x02040658, arm; 16 bytes
// Original: arm9/main @ 0x02040648; symbol: func_02040648; size: 0x10.
extern "C" void Flags_ClearWordBitZero(unsigned int* word) {
    *word &= ~1u;
}
