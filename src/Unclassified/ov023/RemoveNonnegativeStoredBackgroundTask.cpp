#include <globaldefs.h>
ARM
extern "C" {
    void* _ZN16BackgroundLoader11GetInstanceEv();
    void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
}
// Original: arm9/ov023 @ 0x021DB2E4; symbol: func_ov023_021db2e4; size: 0x30.
// Field roles beyond the stated offset operations remain uncertain.
extern "C" void RemoveNonnegativeStoredBackgroundTask(int* task) {
    if(!task)return;
    if(*task<0)return;
    void* loader=_ZN16BackgroundLoader11GetInstanceEv();
    _ZN16BackgroundLoader10RemoveTaskEi(loader,*task);
    *task=-1;
}
