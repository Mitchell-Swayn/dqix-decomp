#include <globaldefs.h>
ARM
extern "C" void System_ActivateGlobalControlForObject(void*,void*);
extern "C" void* WfcUtility_CreateTaskWithBorrowedContext(unsigned,void (*)(void*,void*),void*,unsigned);
// Original: arm9/ov031 @ 0x022277E4; symbol: func_ov031_022277e4; size: 0x20.
extern "C" void* WfcUtility_ScheduleConnectionActivation(void) {
    return WfcUtility_CreateTaskWithBorrowedContext(0, System_ActivateGlobalControlForObject, 0, 0x78);
}
