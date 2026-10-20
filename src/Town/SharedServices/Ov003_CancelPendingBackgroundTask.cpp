#include <globaldefs.h>
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader38ReleaseCompletedBuffersAndRequeueTasksEv();
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*, int);
extern "C" void Bank_ReleaseDialogResources(void*);
// Original: arm9/ov003 @ 0x0216ADBC; symbol: func_ov003_0216adbc; size: 0x50.
extern "C" ARM void Ov003_CancelPendingBackgroundTask(void* owner) {
    unsigned char* p = (unsigned char*)owner;
    if (p[0x5a4]) return;
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    _ZN16BackgroundLoader38ReleaseCompletedBuffersAndRequeueTasksEv();
    _ZN16BackgroundLoader10RemoveTaskEi(loader, *(int*)(p + 0x4e0));
    *(int*)(p + 0x4e0) = -1;
    Bank_ReleaseDialogResources(owner);
    p[0x4ec] = 6;
    p[0x4e8] = 0;
}
