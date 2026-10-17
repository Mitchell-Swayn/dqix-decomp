#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov031_02250c0c[];

// Original: arm9/ov031 @ 0x022274E4; symbol: func_ov031_022274e4; size: 0x28.
extern "C" void Unclassified_CopyGlobalWordsToOptionalOutputs(unsigned int *first, unsigned int *second) {
    if (first != 0)
        *first = data_ov031_02250c0c[4];
    if (second != 0)
        *second = data_ov031_02250c0c[5];
}
