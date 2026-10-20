#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e69c; symbol: data_ov031_0224e69c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* NasServiceLocatorPollRequest_UnknownRoleZeroInitializedStorage;
extern "C" unsigned char NasServiceLocator_DestroySession_TextFREEIntwork;
extern "C" void Memory_ReleaseContextBuffersAndReset(void*);
// Original: arm9/ov031 @ 0x0221A4CC; symbol: RunStoredCallbackAndClearPendingObject; size: 0x4C.
// Prepares the pending global object, invokes its stored callback with the overlay argument block, then clears the global pointer.
extern "C" void NasServiceLocator_DestroySession() {
    if (!NasServiceLocatorPollRequest_UnknownRoleZeroInitializedStorage) return;
    Memory_ReleaseContextBuffersAndReset((char*)NasServiceLocatorPollRequest_UnknownRoleZeroInitializedStorage + 8);
    void (**callback)(void*, void*, int) = (void (**)(void*, void*, int))((char*)NasServiceLocatorPollRequest_UnknownRoleZeroInitializedStorage + 4);
    (*callback)(&NasServiceLocator_DestroySession_TextFREEIntwork, NasServiceLocatorPollRequest_UnknownRoleZeroInitializedStorage, 0);
    NasServiceLocatorPollRequest_UnknownRoleZeroInitializedStorage = 0;
}
