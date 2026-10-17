#include <globaldefs.h>
extern "C" void ClearRecordBuffersAndIndexedCategory(void);
// Original: arm9/main @ 0x0205FACC; symbol: func_0205facc; size: 0x28.
extern "C" void Object_ClearOffset47CThrough498GlobalState(int param_1) {
    ClearRecordBuffersAndIndexedCategory();
    *(unsigned int *)(param_1 + 0x480) = 0;
    *(unsigned int *)(param_1 + 0x47c) = 0;
    *(unsigned int *)(param_1 + 0x494) = 0;
    *(unsigned int *)(param_1 + 0x498) = 0;
    *(unsigned char *)(param_1 + 0x492) = 0;
}
