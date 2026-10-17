#include <globaldefs.h>
ARM
extern "C" void _ZN18VRAMStagingManager4Task5ResetEv(void *);
// Original: arm9/itcm @ 0x01FF96D4; symbol: func_01ff96d4; size: 0x14.
extern "C" void *VRAMStagingManager_TaskReset(void *task) {
    _ZN18VRAMStagingManager4Task5ResetEv(task);
    return task;
}
