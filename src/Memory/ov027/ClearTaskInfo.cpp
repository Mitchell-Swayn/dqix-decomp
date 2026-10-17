#include <globaldefs.h>
ARM
extern "C" void VectorizedMemset(void *destination, int value, unsigned int size);
// Original: arm9/ov027 @ 0x021DD3CC; symbol: func_ov027_021dd3cc; size: 0x14.
extern "C" void ClearTaskInfo(void *taskInfo) {
    VectorizedMemset(taskInfo, 0, 0x20);
}
