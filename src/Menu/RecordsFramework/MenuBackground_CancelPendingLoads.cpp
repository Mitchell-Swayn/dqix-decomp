#include <globaldefs.h>
ARM
extern "C" void Filesystem_CancelStoredBackgroundTasks(void *);
// Original: arm9/ov023 @ 0x021FBDDC; symbol: func_ov023_021fbddc; size: 0x10.
extern "C" void MenuBackground_CancelPendingLoads(void *p) {
    Filesystem_CancelStoredBackgroundTasks((char *)p + 0x20);
}
