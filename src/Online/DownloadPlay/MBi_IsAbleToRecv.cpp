#include <globaldefs.h>
ARM
// Original data: arm9/ov027 @ 0x21dd8b8; symbol: data_ov027_021dd8b8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 020000000000000001000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned IsAbleToLoad_UnknownRoleInitializedBytes[];
// Original: arm9/ov027 @ 0x021DA988; symbol: func_ov027_021da988; size: 0xAC.
// Checks whether a multiboot segment lies within its permitted receive address range.
extern "C" int MBi_IsAbleToRecv(unsigned segment,unsigned address,unsigned length)
{
    switch(IsAbleToLoad_UnknownRoleInitializedBytes[segment]) {
    case 2:
        if(address>=0x027ffe00 && address+length<=0x027fff60) return 1;
        break;
    case 0:
        if(address>=0x02000000 && address+length<=0x022c0000) return 1;
        break;
    case 1:
        if(address>=0x022c0000 && address+length<=0x02300000) return 1;
        if(address>=0x02000000 && address+length<=0x02300000) return 1;
        break;
    default: return 0;
    }
    return 0;
}
