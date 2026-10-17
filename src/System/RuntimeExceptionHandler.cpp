#include "System/RuntimeExceptionCallbacks.h"

#pragma optimize_for_size off
// Original: arm9/main @ 0x0200EFB8; symbol: func_0200efb8; size: 0x18.
extern "C" void RuntimeExceptionHandler_InvokeObservedCallback()
{
    data_020ef070.observedCallback();
}
