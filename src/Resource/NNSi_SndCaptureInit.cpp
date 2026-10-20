#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x210fd74; symbol: data_0210fd74.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int NNSiSndCaptureInit_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020BCE9C; symbol: func_020bce9c; size: 0x18.
void NNSi_SndCaptureInit(){NNSiSndCaptureInit_UnknownRoleZeroInitializedStorage[0]=0;NNSiSndCaptureInit_UnknownRoleZeroInitializedStorage[18]=0;}
}
