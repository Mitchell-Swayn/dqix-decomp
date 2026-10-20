#include <globaldefs.h>
ARM
extern "C" int OS_SendMessage(void *, void *, int);
// Original: arm9/ov031 @ 0x0223FAD4; symbol: func_ov031_0223fad4; size: 0x14.
extern "C" int NasAuth_NotifyRequestCompletionQueue(void *queue) { return OS_SendMessage(queue, 0, 0); }
