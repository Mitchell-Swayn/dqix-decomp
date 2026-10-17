#include <globaldefs.h>
// func_020556cc: 0x020556cc–0x020556dc, arm; 16 bytes
// Original: arm9/main @ 0x020556CC; symbol: func_020556cc; size: 0x10.
extern "C" void WriteThreeWordsAtOffsets28Through30(int self, unsigned int first, unsigned int second, unsigned int third) {
    *(unsigned int*)(self + 0x30) = first;
        *(unsigned int*)(self + 0x2c) = second;
        *(unsigned int*)(self + 0x28) = third;
}
