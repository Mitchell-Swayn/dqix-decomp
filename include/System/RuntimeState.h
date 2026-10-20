#pragma once

typedef void (*RuntimeExitHandler)();
typedef void (*RuntimeSignalHandler)(int);

struct RuntimeExitState {
    RuntimeExitHandler lateHandler;
    RuntimeExitHandler earlyHandler;
    volatile int handlerCount;
    int aborting;
};

struct RuntimeDestructorNode {
    RuntimeDestructorNode* next;
    void (*destroy)(void*, int);
    void* object;
};

// Original data: arm9/main @ 0x20f2e60; symbol: data_020f2e60.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern RuntimeExitState RuntimeAbortProcess_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x20f2e70; symbol: data_020f2e70.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 256 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern RuntimeExitHandler volatile RuntimeRunRegisteredExitHandlersAndTerminate_UnknownRoleZeroInitializedStorage[64];
// Original data: arm9/main @ 0x20f2f70; symbol: data_020f2f70.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage[9];
// Original data: arm9/main @ 0x20f2f94; symbol: data_020f2f94.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage_Variant2[9];
// Original data: arm9/main @ 0x20f3394; symbol: data_020f3394.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern RuntimeSignalHandler RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage_Variant4[7];
// Original data: arm9/main @ 0x20f33b0; symbol: data_020f33b0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern RuntimeDestructorNode* RuntimeRunCleanupCallbacksForMemoryRegion_UnknownRoleZeroInitializedStorage;
