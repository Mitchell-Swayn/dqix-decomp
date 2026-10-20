#include <globaldefs.h>
THUMB
extern "C" void Memory_FillBufferWithLowByteUsingVectorizedMemset(void *, unsigned int, unsigned int);
// Original data: arm9/ov031 @ 0x224f440; symbol: data_ov031_0224f440.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetupSendNegotiationRequest_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x224e6e0; symbol: data_ov031_0224e6e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x224e704; symbol: data_ov031_0224e704.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemInitializeSharedContextFromInputRecord_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x224e700; symbol: data_ov031_0224e700.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage_Variant3[];
extern "C" unsigned int data_ov031_0224f6fc;
// Original: arm9/ov031 @ 0x0221D008; symbol: System_InitializeSharedContextFromInputRecord; size: 0x58.
// Initializes two shared structures and copies input fields into shared records, including the masked low nibble and constant 0xC0A80B01.
extern "C" void System_InitializeSharedContextFromInputRecord(const unsigned char *p) {
    Memory_FillBufferWithLowByteUsingVectorizedMemset(WirelessSetupSendNegotiationRequest_UnknownRoleZeroInitializedStorage, 0, 8);
    *(unsigned int *)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 0x10) = 1;
    Memory_FillBufferWithLowByteUsingVectorizedMemset(SystemInitializeSharedContextFromInputRecord_UnknownRoleZeroInitializedStorage, 0, 0x1c);
    *(void **)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 0x24) = (void *)(p + 6);
    *(unsigned int *)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 0x28) = *(unsigned short *)(p + 4);
    *(unsigned int *)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 0x2c) = *(unsigned short *)p & 0xf;
    AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage_Variant3[0x1d] = p[2];
    *(unsigned int *)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 0x30) = 0;
    *(unsigned int *)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 0x34) = 0xc0a80b01;
    AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage_Variant3[0x1c] = 0;
}
