#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02290d14[];
extern "C" void func_ov027_021dcd20(void);
// Original: arm9/ov031 @ 0x02238DB4; symbol: func_ov031_02238db4; size: 0x30.
extern "C" void System_ProcessMatchingGlobalRecord(void) {
    unsigned short *record = *(unsigned short **)data_ov031_02290d14;
    if (record[0] == 4 && record[1] == record[6])
        func_ov027_021dcd20();
}
