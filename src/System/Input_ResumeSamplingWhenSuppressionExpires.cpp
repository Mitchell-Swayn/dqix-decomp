#include <globaldefs.h>
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2153628; symbol: data_02153628.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" { int TestElapsedTimestampWithinDuration(); extern unsigned TestElapsedTimestampWithinDuration_UnknownRoleZeroInitializedStorage[]; extern char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[],Main_UnknownRoleZeroInitializedStorage_Variant4[]; void Input_SetKeySamplingEnabled(void*,int); void TouchInput_SetSamplingEnabled(void*,int);
// Original: arm9/main @ 0x020E123C; symbol: func_020e123c; size: 0x4C.
 void Input_ResumeSamplingWhenSuppressionExpires() { if(TestElapsedTimestampWithinDuration())return; unsigned* p=TestElapsedTimestampWithinDuration_UnknownRoleZeroInitializedStorage;p[1]=0;p[2]=0;p[0]=0;Input_SetKeySamplingEnabled(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,1);TouchInput_SetSamplingEnabled(Main_UnknownRoleZeroInitializedStorage_Variant4,1); } }
