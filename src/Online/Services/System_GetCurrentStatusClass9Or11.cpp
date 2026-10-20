#include <globaldefs.h>
ARM
extern "C" int System_PollSharedSequenceAndDrainQueue(void);
extern "C" int System_DrainSharedSequenceAndReleaseContext(void);
// Original: arm9/ov031 @ 0x022154F8; symbol: func_ov031_022154f8; size: 0x30.
extern "C" int System_GetCurrentStatusClass9Or11(void) {
    if (System_PollSharedSequenceAndDrainQueue() != 0)
        return 11;
    int status = System_DrainSharedSequenceAndReleaseContext();
    if (status == 0 || status == -39)
        return 9;
    return 11;
}
