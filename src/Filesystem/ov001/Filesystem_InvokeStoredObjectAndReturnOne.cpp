#include <globaldefs.h>
ARM
extern "C" unsigned char data_02108760[];
extern "C" void InvokeObjectWithStoredFieldC0(char *a);
// Original: arm9/ov001 @ 0x02163848; symbol: func_ov001_02163848; size: 0x18.
extern "C" int Filesystem_InvokeStoredObjectAndReturnOne(void) {
    InvokeObjectWithStoredFieldC0((char *)data_02108760);
    return 1;
}
