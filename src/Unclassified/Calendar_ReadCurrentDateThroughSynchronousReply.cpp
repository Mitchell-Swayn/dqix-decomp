#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" void IPC_StoreGlobalReplyValue(void);
extern "C" int InitializeGlobalOperationUnderIRQProtection(unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" void func_020cf864(void);
extern "C" unsigned int data_02111818;
// Original: arm9/main @ 0x020CF0FC; symbol: func_020cf0fc; size: 0x38.
extern "C" unsigned int Calendar_ReadCurrentDateThroughSynchronousReply(unsigned int param_1, unsigned int unused2, unsigned int unused3, unsigned int param_4) {
    int result = InitializeGlobalOperationUnderIRQProtection(param_1, (unsigned int)IPC_StoreGlobalReplyValue, 0, param_4);
    *(unsigned int *)((char *)&data_02111818 + 0x2c) = (unsigned int)result;
    if (result == 0) func_020cf864();
    return *(unsigned int *)((char *)&data_02111818 + 0x2c);
}
