#include <globaldefs.h>
ARM
extern "C" void *_ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" unsigned int _ZN16BackgroundLoader13GetTaskStatusEi(void *, unsigned int);
// Original: arm9/ov000 @ 0x0216FD38; symbol: func_ov000_0216fd38; size: 0x48.
extern "C" int Ov000_IsBackgroundTaskComplete(char *task) {
    if (*(unsigned char *)(task + 0xa0)) return 1;
    if (*(int *)task < 0) return 0;
    unsigned int status = _ZN16BackgroundLoader13GetTaskStatusEi(_ZN16BackgroundLoader11GetInstanceEv(), *(unsigned int *)task);
    if (status == 0) return 0;
    *(unsigned char *)(task + 0xa0) = 1;
    return 1;
}
