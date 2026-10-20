#include <globaldefs.h>
ARM
extern "C" void MIi_CpuCopyFast(const void*,void*,unsigned);
// Original data: arm9/ov016 @ 0x219d1c0; symbol: data_ov016_0219d1c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" unsigned GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov016 @ 0x219cbe0; symbol: data_ov016_0219cbe0.
// Movie RGB555 conversion lookup, input biased by 256; output saturates to 0..31 after division by eight.
// Initial values: hex 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 ...; full span in module reference.
// Observed span: 768 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" unsigned char FilesystemReadNextBufferedChunk_MovieRGB555ConversionLookupInputBiasedBy256[];
// Original: arm9/ov016 @ 0x0218FDC0; symbol: Filesystem_ReadNextBufferedChunk; size: 0x70.
extern "C" void* Filesystem_ReadNextBufferedChunk(void) { if(!GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[0]){if(GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[3]>=0x300){GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[0]=GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[4]; MIi_CpuCopyFast(FilesystemReadNextBufferedChunk_MovieRGB555ConversionLookupInputBiasedBy256,(void*)GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[4],0x300); GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[4]+=0x300; GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[3]-=0x300;}else return FilesystemReadNextBufferedChunk_MovieRGB555ConversionLookupInputBiasedBy256;} return (void*)GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[0]; }
