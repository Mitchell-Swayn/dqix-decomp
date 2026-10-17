#include <globaldefs.h>
// func_02040658: 0x02040658–0x02040668, arm; 16 bytes
// Original: arm9/main @ 0x02040658; symbol: func_02040658; size: 0x10.
extern "C" void SetWordBit0(unsigned int* word) {
    *word |= 1;
}
