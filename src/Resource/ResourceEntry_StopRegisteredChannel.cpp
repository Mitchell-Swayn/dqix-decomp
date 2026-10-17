#include <globaldefs.h>
extern "C" {
void ProcessEightMaskBitsAndDispatchCommandThirteen(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int ReadSelectedGlobalValueUnderIRQProtection(void);
void func_020d24c4(unsigned int);
void SoundCommand_WaitUntilRecordCompletes(unsigned int);
// Original: arm9/main @ 0x020BCDE0; symbol: func_020bcde0; size: 0x4C.
ARM void ResourceEntry_StopRegisteredChannel(unsigned int *param_1) {
    int shifted = (int)(param_1[9] << 30);
    int sign = shifted >> 31;
    if (sign == 0) return;
    ProcessEightMaskBitsAndDispatchCommandThirteen(param_1[17], 0, 1u << param_1[16], 0);
    unsigned int result = ReadSelectedGlobalValueUnderIRQProtection();
    func_020d24c4(1);
    SoundCommand_WaitUntilRecordCompletes(result);
}
}
