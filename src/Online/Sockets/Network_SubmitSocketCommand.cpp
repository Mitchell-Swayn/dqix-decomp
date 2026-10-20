#include <globaldefs.h>
ARM
// Original: arm9/ov031:0220520c; For request mode byte +0xd equal to one, publishes a stack queue and receives its result; otherwise clears request +8 and returns the handler result.
extern "C" void OS_InitMessageQueue(int*, int*, int);
extern "C" int MessageQueue_ReceiveWithOptionalBlocking(void*, unsigned*, unsigned);
extern "C" int System_SendMessageWithOverlayFallback(void*, void*);
extern "C" int Network_SubmitSocketCommand(void* self, char* request) {
    unsigned output;
    int init;
    int queue[8];
    if (*(signed char*)(request + 0xD) == 1) {
        OS_InitMessageQueue(queue, &init, 1);
        *(int**)(request + 8) = queue;
        System_SendMessageWithOverlayFallback(self, request);
        MessageQueue_ReceiveWithOptionalBlocking(queue, &output, 1);
    } else {
        *(int**)(request + 8) = 0;
        output = System_SendMessageWithOverlayFallback(self, request);
    }
    return output;
}
