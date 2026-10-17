#include <globaldefs.h>
// func_0203a46c: 0x0203a46c–0x0203a47c, arm; 16 bytes
// Original: arm9/main @ 0x0203A46C; symbol: func_0203a46c; size: 0x10.
extern "C" void SetThreeWordFieldsAtOffsets1C20And24(int self, unsigned int first, unsigned int second, unsigned int third) {
    *(unsigned int*)(self + 0x1c) = first;
        *(unsigned int*)(self + 0x20) = second;
        *(unsigned int*)(self + 0x24) = third;
}
