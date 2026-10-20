#include <globaldefs.h>
ARM
// Original data: arm9/ov027 @ 0x21dd8b8; symbol: data_ov027_021dd8b8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 020000000000000001000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned IsAbleToLoad_UnknownRoleInitializedBytes[];
extern "C" int MBi_IsAbleToRecv(unsigned,unsigned,unsigned);
// Original: arm9/ov027 @ 0x021DAA34; symbol: func_ov027_021daa34; size: 0xCC.
// Validates a segment load span against main RAM and ARM7 work RAM limits.
extern "C" int IsAbleToLoad(unsigned segment,unsigned address,unsigned length)
{
    switch(IsAbleToLoad_UnknownRoleInitializedBytes[segment]) {
    case 0: case 2: return MBi_IsAbleToRecv(segment,address,length);
    case 1:
        if(address>=0x02000000 && address<0x023fe800) {
            unsigned end=address+length;
            if(address<0x02300000 && end>0x02300000) return 0;
            if(end<=0x02300000) return 1;
            if(end<0x023fe800 && length<=0x40000)return 1;
            return 0;
        }
        if(address>=0x037f8000 && address<0x0380f000) return address+length<=0x0380f000;
        break;
    default:return 0;
    }
    return 0;
}
