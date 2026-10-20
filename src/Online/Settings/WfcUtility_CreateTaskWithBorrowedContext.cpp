#include <globaldefs.h>
ARM
extern "C" void WfcUtility_CreatePriorityTask(void *, void *, void *, void *, int);
// Original: arm9/ov031 @ 0x0223E218; symbol: func_ov031_0223e218; size: 0x14.
extern "C" void WfcUtility_CreateTaskWithBorrowedContext(void *arg0, void *arg1, void *arg2, void *arg3) {
    WfcUtility_CreatePriorityTask(arg0, arg1, arg2, arg3, 0);
}
