#include <globaldefs.h>
ARM

extern "C" void *Unclassified_InvokeHelperWithZeroFifthArgument(unsigned, void (*)(void), void *, unsigned);
extern "C" void func_ov031_0223c2d0(void);
extern "C" unsigned char *data_ov031_02290d34;

// Original: arm9/ov031 @ 0x0223C278; symbol: func_ov031_0223c278; size: 0x58.
extern "C" int System_QueueTimedCallbackForSharedRecord(unsigned short value) {
    unsigned char *record = data_ov031_02290d34;
    if (record[9] != 0) {
        return 0;
    }
    *(void **)record = Unclassified_InvokeHelperWithZeroFifthArgument(1, func_ov031_0223c2d0, record, 0xC8);
    *(unsigned short *)(record + 4) = 0;
    *(unsigned short *)(record + 6) = value;
    record[9] = 1;
    return 1;
}
