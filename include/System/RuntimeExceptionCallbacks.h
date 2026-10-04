#pragma once

typedef void (*RuntimeExceptionCallback)();

struct RuntimeExceptionCallbacks {
    RuntimeExceptionCallback observedCallback;
    RuntimeExceptionCallback unknownCallback;
};

extern RuntimeExceptionCallbacks data_020ef070;
typedef char RuntimeExceptionCallbacksSizeCheck[
    sizeof(RuntimeExceptionCallbacks) == 8 ? 1 : -1];
