#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e5e8; symbol: data_ov031_0224e5e8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* NasAuthDestroySession_UnknownRoleZeroInitializedStorage;
extern "C" unsigned char NasAuth_DestroySession_TextFREEDWCauth[];
extern "C" void Memory_ReleaseContextBuffersAndReset(void);
typedef void (*DispatchCallback)(void*, void*, unsigned);
// Original: arm9/ov031 @ 0x02216A2C; symbol: func_ov031_02216a2c; size: 0x58.
extern "C" void NasAuth_DestroySession(void) {
    void* object = (void*)*(volatile void**)((char*)&NasAuthDestroySession_UnknownRoleZeroInitializedStorage + 8);
    if (!object)
        return;
    unsigned char* state = (unsigned char*)object + 0x1000;
    DispatchCallback callback = *(DispatchCallback*)(state + 0x210);
    if (*(void**)(state + 0x314))
        Memory_ReleaseContextBuffersAndReset();
    callback(NasAuth_DestroySession_TextFREEDWCauth, (void*)*(volatile void**)((char*)&NasAuthDestroySession_UnknownRoleZeroInitializedStorage + 8), 0);
    *(volatile void**)((char*)&NasAuthDestroySession_UnknownRoleZeroInitializedStorage + 8) = 0;
}
