#include <globaldefs.h>
ARM
// Original data: arm9/ov027 @ 0x21e33ec; symbol: data_ov027_021e33ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char *MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2;
struct SegmentBlocks { unsigned offsets[3]; unsigned short first[3],total; };
struct SegmentInfo { unsigned base,unused,length,other; };
struct BlockInfo { unsigned source,length,destination; unsigned char segment; };
struct ParentBlockContext { unsigned char pad[0x1318]; unsigned blockSize; };
// Original: arm9/ov027 @ 0x021DA8D4; symbol: func_ov027_021da8d4; size: 0xB4.
// Maps a transfer block index to its segment, clipped length and source/destination ranges.
extern "C" int GetTransferBlockInfo(BlockInfo *out,SegmentBlocks *blocks,unsigned short block,unsigned char *file)
{
    unsigned relative,offset;
    if(block>=blocks->total)return 0;
    signed char segment;
    for(segment=2;segment>=0;segment--) if(block>=blocks->first[segment])break;
    if(segment<0)return 0;
    relative=blocks->first[segment];
    relative=block-relative;
    offset=relative*((ParentBlockContext*)MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2)->blockSize;
    SegmentInfo *info=(SegmentInfo*)(file+12)+segment;
    unsigned remaining=info->length-offset;
    out->length=remaining;
    if(remaining>((ParentBlockContext*)MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2)->blockSize)out->length=((ParentBlockContext*)MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2)->blockSize;
    out->destination=offset+blocks->offsets[segment];
    out->source=offset+info->base;
    out->segment=segment;
    return 1;
}
