#include <globaldefs.h>
ARM
extern "C" { typedef void WfcTaskCallback(void*, void*); }
extern "C" void* WfcUtility_CreatePriorityTask(unsigned, WfcTaskCallback*, void*, unsigned, unsigned char);
// Original: arm9/ov031 @ 0x0223E218; symbol: func_ov031_0223e218; size: 0x14.
extern "C" void* WfcUtility_CreateTaskWithBorrowedContext(unsigned arg0, WfcTaskCallback* arg1, void *arg2, unsigned arg3) {
    return WfcUtility_CreatePriorityTask(arg0, arg1, arg2, arg3, 0);
}
