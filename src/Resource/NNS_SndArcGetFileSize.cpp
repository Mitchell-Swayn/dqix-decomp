#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2110370; symbol: data_02110370.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char* NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020BD79C; symbol: func_020bd79c; size: 0x28.
 extern "C" unsigned int NNS_SndArcGetFileSize(unsigned int i) { unsigned char* p=*(unsigned char**)(NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage+0x84); if(i>=*(unsigned int*)(p+8))return 0; return *(unsigned int*)(p+i*16+0x10); }
