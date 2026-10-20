#include <globaldefs.h>
ARM
extern "C" void BackgroundLoader_RemoveAllQueuedTasks(void);

// Original: arm9/ov001 @ 0x0215EF44; symbol: func_ov001_0215ef44; size: 0x10.
extern "C" int BackgroundLoader_ClearTasksAndReturnSuccess(void) {
    BackgroundLoader_RemoveAllQueuedTasks();
    return 1;
}
