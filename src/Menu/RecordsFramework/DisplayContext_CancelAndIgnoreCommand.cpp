#include <globaldefs.h>
ARM
extern "C" unsigned int DisplayContext_GetGlobalInstance();
extern "C" void BackgroundLoader_CancelEightTasksAndResetState(int);
extern "C" void DisplayContext_IgnoreHook(void *);
extern "C" void DisplayContext_IgnoreCommand(void *, int, int, int, int);
// Original: arm9/ov023 @ 0x021FD2B8; symbol: func_ov023_021fd2b8; size: 0x40.
extern "C" int DisplayContext_CancelAndIgnoreCommand(void *p) {
    unsigned int context = DisplayContext_GetGlobalInstance();
    BackgroundLoader_CancelEightTasksAndResetState(context);
    DisplayContext_IgnoreHook((void *)context);
    DisplayContext_IgnoreCommand((void *)context,
        *(int *)((char *)p + 0x20), *(int *)((char *)p + 0x24),
        *(unsigned char *)((char *)p + 0x28), *(unsigned char *)((char *)p + 0x29));
    return 1;
}
