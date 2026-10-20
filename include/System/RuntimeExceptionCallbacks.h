#pragma once

typedef void (*RuntimeExceptionCallback)();

struct RuntimeExceptionCallbacks {
    RuntimeExceptionCallback observedCallback;
    RuntimeExceptionCallback unknownCallback;
};

// Original data: arm9/main @ 0x20ef070; symbol: data_020ef070.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex a0ef0002acef0002.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern RuntimeExceptionCallbacks RuntimeExceptionHandlerInvokeObservedCallback_UnknownRoleProcedureReferenceRecords;
typedef char RuntimeExceptionCallbacksSizeCheck[
    sizeof(RuntimeExceptionCallbacks) == 8 ? 1 : -1];
