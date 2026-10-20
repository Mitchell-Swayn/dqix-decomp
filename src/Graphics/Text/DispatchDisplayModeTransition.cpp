#include <globaldefs.h>
#pragma optimize_for_size off
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];extern "C" void Text_ProcessBufferedHalfwordCodesAndResetCounters(void*);extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(void*,int,int);extern "C" void TextStream_SeekControlTokenAndRebuildBuffers(void*,int,int);extern "C" void TextLayout_ResetBuffersAndLoadedLineEntries(void*);
// Original: arm9/main @ 0x020679D4; symbol: func_020679d4; size: 0xC8.
extern "C" ARM void DispatchDisplayModeTransition(char* p,int mode){if(mode!=-2){switch(mode){case 0:{Text_ProcessBufferedHalfwordCodesAndResetCounters(p);SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);TextStream_SeekControlTokenAndRebuildBuffers(p,0xff16,*(int*)(p+88));TextLayout_ResetBuffersAndLoadedLineEntries(p+144);p[0x19cd]=1;*(int*)(p+64)=0;return;}case 1:SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);break;default:return;}}*(int*)(p+0x954)=1;Text_ProcessBufferedHalfwordCodesAndResetCounters(p);TextStream_SeekControlTokenAndRebuildBuffers(p,0xff17,*(int*)(p+88));TextLayout_ResetBuffersAndLoadedLineEntries(p+144);p[0x19cd]=1;*(int*)(p+64)=0;}
