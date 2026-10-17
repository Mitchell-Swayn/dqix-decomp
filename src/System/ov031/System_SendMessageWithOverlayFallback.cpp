#include <globaldefs.h>
ARM
extern "C" int OS_SendMessage(void *queue, void *message, int flags);
extern "C" int SendMessageToOverlayQueueIfArgumentPresent(void *message);
// Original: arm9/ov031 @ 0x022051A8; symbol: func_ov031_022051a8; size: 0x4C.
extern "C" int System_SendMessageWithOverlayFallback(void *queue, void *message) {
    int flags;
    if (message == 0) goto flag_one;
    if ((*(signed char *)((char *)message + 0xD) & 1) == 0) goto flag_zero;
flag_one:
    flags = 1;
    goto send;
flag_zero:
    flags = 0;
send:
    int result = OS_SendMessage(queue, message, flags);
    if (result == 0) SendMessageToOverlayQueueIfArgumentPresent(message);
    return result != 0 ? 0 : -42;
}
