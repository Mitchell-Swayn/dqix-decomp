#pragma optimize_for_size off
#include <globaldefs.h>
ARM
#include "System/ProcessorContext.h"
#include "System/Interrupts.h"
struct OSMessageQueue {
    BlockedContextList queueSend;
    BlockedContextList queueReceive;
    void** msgArray;
    int msgCount;
    int firstIndex;
    int usedCount;
};
// Original: arm9/main @ 0x020C7E0C; symbol: func_020c7e0c; size: 0x94.
// NitroSDK OS_SendMessage enqueues a message, optionally waiting for capacity.
extern "C" int OS_SendMessage(OSMessageQueue* queue, void* message, int flags)
{
    int enabled = DisableIRQInterrupts();
    if (queue->msgCount <= queue->usedCount) {
      do {
        if (!(flags & 1)) {
            SetIRQInterruptState(enabled);
            return 0;
        }
        BlockCurrentContext(&queue->queueSend);
      } while (queue->msgCount <= queue->usedCount);
    }
    int lastIndex = (queue->firstIndex + queue->usedCount) % queue->msgCount;
    queue->msgArray[lastIndex] = message;
    queue->usedCount++;
    UnblockContexts(&queue->queueReceive);
    SetIRQInterruptState(enabled);
    return 1;
}
