#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x2110370; symbol: data_02110370.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020BD444; symbol: func_020bd444; size: 0x10.
unsigned int NNS_SndArcGetCurrent(){return NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage;}
}
