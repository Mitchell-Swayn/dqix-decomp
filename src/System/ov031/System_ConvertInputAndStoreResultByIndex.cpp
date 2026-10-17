#include <globaldefs.h>
ARM
extern unsigned int data_ov031_02290d2c[];
extern "C" unsigned int func_ov031_0223b61c(void *, unsigned char *, int);
// Original: arm9/ov031 @ 0x0223BD58; symbol: func_ov031_0223bd58; size: 0x30.
extern "C" void System_ConvertInputAndStoreResultByIndex(int index, void *input) {
    unsigned char byte;
    unsigned int result = func_ov031_0223b61c(input, &byte, 4);
    data_ov031_02290d2c[index] = result;
}
