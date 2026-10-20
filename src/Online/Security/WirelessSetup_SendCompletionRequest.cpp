#include <globaldefs.h>
THUMB
// Original data: arm9/ov031 @ 0x224e6e0; symbol: data_ov031_0224e6e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage[];
extern "C" unsigned char WirelessSetup_SendCompletionRequest_TextMELCO[];
extern "C" void Memory_FillBufferWithLowByteUsingVectorizedMemset(void *, unsigned int, unsigned int);
extern "C" void System_Copy8WithReversedPointers(void *, const void *, unsigned int);
extern "C" unsigned int Util_GetStringLength(const char *);
extern "C" void WirelessSetup_TransformRequestToken(void *, unsigned int, void *, unsigned int);
extern "C" void WirelessSetup_WriteRequestHeader(void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, void *);
extern "C" void WirelessSetup_SendRequestDatagram(void *, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov031 @ 0x0221DEDC; symbol: func_ov031_0221dedc; size: 0x6C.
extern "C" int WirelessSetup_SendCompletionRequest(void *unused, const unsigned char *data, unsigned int value) {
    void *context = *(void **)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 0x14);
    Memory_FillBufferWithLowByteUsingVectorizedMemset(context, 0, 0x5dc);
    unsigned char buffer[8];
    System_Copy8WithReversedPointers(buffer, data + 0x10, 8);
    unsigned int name = Util_GetStringLength((const char *)WirelessSetup_SendCompletionRequest_TextMELCO);
    WirelessSetup_TransformRequestToken(buffer, 8, WirelessSetup_SendCompletionRequest_TextMELCO, name);
    WirelessSetup_WriteRequestHeader(context, 0x3000, 0, 0, 0, 0x11, buffer);
    WirelessSetup_SendRequestDatagram(context, 0x18, 0, value);
    return 0;
}
