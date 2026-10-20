#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
ARM void* ColorAnimation_GetGlobalInstance(); void ColorAnimation_StartParameterizedTransition(void*,void*,int,int,int); void SoundSfx_StartCurrentSequenceArchiveEntry(void*,int,int); extern unsigned char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0208AD1C; symbol: func_0208ad1c; size: 0x4C.
 void PartyProgress_PlayCompletionColorEffect(unsigned char* self) { void* value=ColorAnimation_GetGlobalInstance(); if(value) { ColorAnimation_StartParameterizedTransition(value,self+12,20,5,15); SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,120,0); } }
}
