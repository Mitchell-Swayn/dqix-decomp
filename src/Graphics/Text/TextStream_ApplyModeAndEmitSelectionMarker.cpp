#include <globaldefs.h>
#pragma optimize_for_size off
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];extern "C" void Text_ProcessBufferedHalfwordCodesAndResetCounters(void*);extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(void*,int,int);extern "C" void TextStream_SeekControlTokenAndRebuildBuffers(void*,int,int);extern "C" void TextLayout_ResetBuffersAndLoadedLineEntries(void*);
// Original: arm9/main @ 0x020678BC; symbol: func_020678bc; size: 0x118.
extern "C" ARM void TextStream_ApplyModeAndEmitSelectionMarker(char* p,int mode){unsigned value=(*(unsigned short**)(p+0x4c))[*(int*)(p+0x78)];bool first=value==0xff06;bool second=value==0xff07;if(mode!=-2){switch(mode){case 0:Text_ProcessBufferedHalfwordCodesAndResetCounters(p);if(!first)SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);TextStream_SeekControlTokenAndRebuildBuffers(p,0xff14,*(int*)(p+0x58));TextLayout_ResetBuffersAndLoadedLineEntries(p+0x90);p[0x19cd]=1;*(int*)(p+0x40)=0;return;case 1:if(!first&&!second)SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);break;default:return;}}*(int*)(p+0x954)=1;Text_ProcessBufferedHalfwordCodesAndResetCounters(p);TextStream_SeekControlTokenAndRebuildBuffers(p,0xff15,*(int*)(p+0x58));TextLayout_ResetBuffersAndLoadedLineEntries(p+0x90);p[0x19cd]=1;*(int*)(p+0x40)=0;}
