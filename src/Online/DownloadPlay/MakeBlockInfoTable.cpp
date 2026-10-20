#include <globaldefs.h>
ARM
// Original data: arm9/ov027 @ 0x21e33ec; symbol: data_ov027_021e33ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char *MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2;
extern "C" int IsAbleToLoad(unsigned,unsigned,unsigned);
struct BlockTable { unsigned offsets[3]; unsigned short first[3],total; };
struct ImageSegment { unsigned source,address,length,unused; };
struct ImageInfo { unsigned char pad[12]; ImageSegment segments[3]; };
struct ParentContext { unsigned char pad[0x1318]; unsigned blockSize; };
// Original: arm9/ov027 @ 0x021DA808; symbol: func_ov027_021da808; size: 0xCC.
// Builds cumulative segment offsets and block boundaries after validating each load span.
extern "C" int MakeBlockInfoTable(BlockTable *table,ImageInfo *image)
{
    ImageSegment *segments;
    unsigned short *first=table->first;
    ImageSegment *info;
    unsigned length;
    unsigned char segment;
    unsigned offset=0;
    if(!image)return 0;
    for(unsigned char i=0;i<3;i++) { table->offsets[i]=offset; offset+=image->segments[i].length; }
    first[0]=0;
    segments=image->segments;
    for(segment=0;segment<3;segment++) {
        info=segments+segment;
        unsigned size=((ParentContext*)MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2)->blockSize;
        length=info->length;
        unsigned short count=(length+size-1)/size;
        unsigned short end=first[segment]+count;
        if(!IsAbleToLoad(segment,info->address,length))return 0;
        if(segment<2)first[segment+1]=end;
        else table->total=end;
    }
    return 1;
}
