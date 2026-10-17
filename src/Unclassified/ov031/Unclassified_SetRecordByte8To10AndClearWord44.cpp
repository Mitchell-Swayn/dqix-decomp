#include <globaldefs.h>
ARM
#pragma optimization_level 1
extern "C" unsigned int data_02111304[];

// Original: arm9/ov031 @ 0x02203190; symbol: func_ov031_02203190; size: 0x2C.
extern "C" void Unclassified_SetRecordByte8To10AndClearWord44(void) {
    unsigned char *record = *(unsigned char **)(data_02111304[1] + 0xa4);
    if (record == 0)
        return;
    record[8] = 10;
    *(unsigned int *)(record + 0x44) = 0;
}
