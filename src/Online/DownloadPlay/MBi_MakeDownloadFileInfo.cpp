#include <globaldefs.h>
#include <System/Memory.h>
ARM
struct BootHeader; struct SegmentOutput;
extern "C" void MBi_SetSegmentInfo(BootHeader*,unsigned*,SegmentOutput*,unsigned*);
// Original data: arm9/ov027 @ 0x21dd8b8; symbol: data_ov027_021dd8b8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 020000000000000001000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned IsAbleToLoad_UnknownRoleInitializedBytes[];
// Original: arm9/ov027 @ 0x021DA61C; symbol: func_ov027_021da61c; size: 0x74.
// Builds three download segments, entry addresses and the extended ROM-header metadata.
extern "C" void MBi_MakeDownloadFileInfo(unsigned char *out,unsigned char *header)
{
    unsigned receiveCursor=0x022c0000;
    *(unsigned*)out=*(unsigned*)(header+0x24);
    *(unsigned*)(out+4)=*(unsigned*)(header+0x34);
    unsigned *type=IsAbleToLoad_UnknownRoleInitializedBytes;
    unsigned char *segment=out+12;
    for(int i=0;i<3;i++,segment+=16,type++)MBi_SetSegmentInfo((BootHeader*)header,type,(SegmentOutput*)segment,&receiveCursor);
    MI_CpuCopy8(header+0x160,out+0x3c,0x88);
}
