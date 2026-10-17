#include <globaldefs.h>
// func_020e1374: 0x020e1374–0x020e1384, arm; 16 bytes
// Original: arm9/main @ 0x020E1374; symbol: func_020e1374; size: 0x10.
extern "C" void SetTwoWordsAndByteAtOffsetsC10And14(int self, unsigned int first, unsigned int second, unsigned char third) {
    *(unsigned int*)(self + 0x0c) = first;
        *(unsigned int*)(self + 0x10) = second;
        *(unsigned char*)(self + 0x14) = third;
}
