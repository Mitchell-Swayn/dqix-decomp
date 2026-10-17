#include <globaldefs.h>
extern "C" void* data_ov031_0224e204;
extern "C" int OS_SendMessage(void* queue, void* message, int flags);
// Sends the input value to the overlay queue when it is nonzero.
// Original: arm9/ov031 @ 0x02205174; symbol: func_ov031_02205174; size: 0x20.
extern "C" ARM void SendMessageToOverlayQueueIfArgumentPresent(void* message)
{
    if (message) OS_SendMessage(&data_ov031_0224e204, message, 0);
}
