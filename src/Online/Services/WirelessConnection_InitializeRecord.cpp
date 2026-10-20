#include <globaldefs.h>
ARM

extern "C" void VectorizedMemset(void *, int, unsigned int);
extern "C" void Ssl_SetCryptoThreadPriority(unsigned int value);
// Original data: arm9/ov031 @ 0x224e5b4; symbol: data_ov031_0224e5b4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov031 @ 0x02211BD4; symbol: func_ov031_02211bd4; size: 0x64.
extern "C" void WirelessConnection_InitializeRecord(void *record, unsigned short value, void *unused, unsigned int callbackValue) {
    if (*(void **)(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage + 4) != 0) {
        return;
    }
    VectorizedMemset(record, 0, 0x64);
    *(unsigned short *)((char *)record + 8) = value;
    *(unsigned short *)((char *)record + 0xa) = 1;
    *(unsigned short *)((char *)record + 4) = 1;
    *(unsigned short *)((char *)record + 6) = 0;
    *((unsigned char *)record + 0xc) = 0;
    *(unsigned int *)((char *)record + 0x10) = 0;
    *(void **)(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage + 4) = record;
    Ssl_SetCryptoThreadPriority(callbackValue);
}
