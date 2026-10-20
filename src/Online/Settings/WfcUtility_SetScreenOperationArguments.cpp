#include <globaldefs.h>
struct MainLoopWords {unsigned char preceding[0x18]; unsigned int words[2];};
// Original data: arm9/ov031 @ 0x2250c0c; symbol: data_ov031_02250c0c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" MainLoopWords Ov031GetStatusCode_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0222750C; symbol: func_ov031_0222750c; size: 0x14.
// Layout projection only; broader object ownership remains unclassified.
extern "C" ARM void WfcUtility_SetScreenOperationArguments(unsigned int a,unsigned int b) {Ov031GetStatusCode_UnknownRoleZeroInitializedStorage.words[0]=a; Ov031GetStatusCode_UnknownRoleZeroInitializedStorage.words[1]=b;}
