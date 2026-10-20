#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20fb3cc; symbol: data_020fb3cc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char* TouchInputClearResumePendingOnSample_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x02012BBC; symbol: func_02012bbc; size: 0x1C.
extern "C" void TouchInput_ClearResumePendingOnSample(int id){if(id==16)TouchInputClearResumePendingOnSample_UnknownRoleZeroInitializedStorage[0x62]=0;}
