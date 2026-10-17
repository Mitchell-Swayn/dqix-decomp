#include "System/RuntimeExceptionCallbacks.h"

extern "C" void Runtime_AbortThroughExitHandler();
extern "C" void Runtime_InvokeObservedExceptionCallback();

RuntimeExceptionCallbacks data_020ef070 = {Runtime_AbortThroughExitHandler, Runtime_InvokeObservedExceptionCallback};
