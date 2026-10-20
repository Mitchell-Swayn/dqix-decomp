#include <globaldefs.h>
ARM
extern "C" int WirelessBeaconScan_GetWorkspaceSize();
extern "C" void* OnlineMemory_AllocateAligned(void*, void*);
extern "C" void VectorizedMemset(void*, int, unsigned int);
// Original data: arm9/ov031 @ 0x224e5dc; symbol: data_ov031_0224e5dc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* Ov031SetGlobalFieldToFour_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x022162F0; symbol: System_InitializeSharedContextObject; size: 0x70.
// Allocates and zeroes a 0x794-byte global object, writes the two caller-provided fields, and clears its control word.
extern "C" int System_InitializeSharedContextObject(void* first, void* second) {
    void* a = OnlineMemory_AllocateAligned((void*)1, (void*)WirelessBeaconScan_GetWorkspaceSize());
    *(void**)((char*)&Ov031SetGlobalFieldToFour_UnknownRoleZeroInitializedStorage + 4) = a;
    void* b = OnlineMemory_AllocateAligned((void*)1, (void*)0x794);
    *(void**)&Ov031SetGlobalFieldToFour_UnknownRoleZeroInitializedStorage = b;
    VectorizedMemset(b, 0, 0x794);
    *(void**)(*(void**)&Ov031SetGlobalFieldToFour_UnknownRoleZeroInitializedStorage) = first;
    *(void**)((char*)*(void**)&Ov031SetGlobalFieldToFour_UnknownRoleZeroInitializedStorage + 0x790) = second;
    *(unsigned int*)((char*)&Ov031SetGlobalFieldToFour_UnknownRoleZeroInitializedStorage + 8) = 0;
    return 1;
}
