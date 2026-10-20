#include <globaldefs.h>
// func_02066ce0: 0x02066ce0–0x02066cf0, arm; 16 bytes
// Original: arm9/main @ 0x02066CE0; symbol: func_02066ce0; size: 0x10.
extern "C" void TextEntry_SetDrawPositionAndDepth(int self, unsigned int first, unsigned int second, unsigned short third) {
    *(unsigned int*)(self + 0x0c) = first;
        *(unsigned int*)(self + 0x10) = second;
        *(unsigned short*)(self + 0x14) = third;
}
