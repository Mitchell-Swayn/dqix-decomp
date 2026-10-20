#include <globaldefs.h>
ARM
extern "C" unsigned int DisplayContext_GetGlobalInstance(void);
extern "C" int DisplayContext_ReportRequestComplete(void);
// Original: arm9/ov023 @ 0x021FD2F8; symbol: func_ov023_021fd2f8; size: 0x20.
extern "C" unsigned int ReadDisplayContextThenReturnTwoOrStoredWord(void *object) {
    DisplayContext_GetGlobalInstance();
    if (DisplayContext_ReportRequestComplete())
        return 2;
    return *(unsigned int *)((char *)object + 0x1c);
}
