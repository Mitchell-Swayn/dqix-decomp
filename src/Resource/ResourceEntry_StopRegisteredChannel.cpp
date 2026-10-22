#include <globaldefs.h>
extern "C" {
void SoundCommand_SubmitOpcodeThirteenAndTrackMask(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int ReadSelectedGlobalValueUnderIRQProtection(void);
int SoundCommand_FlushPendingBatch(unsigned int flags);
void SoundCommand_WaitForCompletionTarget(unsigned int);
// Original: arm9/main @ 0x020BCDE0; symbol: func_020bcde0; size: 0x4C.
ARM void ResourceEntry_StopRegisteredChannel(unsigned int *param_1) {
    int shifted = (int)(param_1[9] << 30);
    int sign = shifted >> 31;
    if (sign == 0) return;
    SoundCommand_SubmitOpcodeThirteenAndTrackMask(param_1[17], 0, 1u << param_1[16], 0);
    unsigned int result = ReadSelectedGlobalValueUnderIRQProtection();
    SoundCommand_FlushPendingBatch(1);
    SoundCommand_WaitForCompletionTarget(result);
}
}
