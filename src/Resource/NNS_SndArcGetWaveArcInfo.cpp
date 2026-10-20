#pragma optimize_for_size off
#pragma optimization_level 4
#include <globaldefs.h>
struct Blob { char pad[0x14];unsigned indexOffset; };
struct BlobOwner { char pad[0x8c];Blob* blob; };
// Original data: arm9/main @ 0x2110370; symbol: data_02110370.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" BlobOwner* NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020BD580; symbol: func_020bd580; size: 0x64.
extern "C" void* NNS_SndArcGetWaveArcInfo(unsigned index) {BlobOwner* owner=NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage;Blob* blob=owner->blob;unsigned* table=blob->indexOffset==0?0:(unsigned*)((char*)blob+blob->indexOffset);if(!table)return 0;if((int)index<0)return 0;if(index>=*table)return 0;unsigned offset=*(unsigned*)((char*)(table+index)+4);Blob* base=owner->blob;return offset==0?0:(char*)base+offset;}
