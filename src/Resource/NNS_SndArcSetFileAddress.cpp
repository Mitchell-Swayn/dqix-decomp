#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x2110370; symbol: data_02110370.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int **NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020BD8D4; symbol: func_020bd8d4; size: 0x1C.
void NNS_SndArcSetFileAddress(int i,unsigned int v){unsigned int *p=NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage[0x21];*(unsigned int *)((char *)p+i*16+0x14)=v;}
}
