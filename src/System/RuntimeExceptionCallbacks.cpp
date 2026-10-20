#include "System/RuntimeExceptionCallbacks.h"

extern "C" void Runtime_AbortThroughExitHandler();
extern "C" void Runtime_InvokeObservedExceptionCallback();

RuntimeExceptionCallbacks RuntimeExceptionHandlerInvokeObservedCallback_UnknownRoleProcedureReferenceRecords = {Runtime_AbortThroughExitHandler, Runtime_InvokeObservedExceptionCallback};
