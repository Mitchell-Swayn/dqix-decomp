#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x20e9138; symbol: data_020e9138.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 05010601070108015400550056005700.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned short Zone3DApplyMappedTripleInstanceVisibility_UnknownRoleInitializedBytes[];
    unsigned char *GameState_GetSerializedProgressState();
    int BitArray_ReadNonnegativeIndexMask(void *,void *,unsigned short);
    void Zone3D_UpdateThreeIndexedInstancesInMatchingZone(unsigned char,unsigned char);
// Original: arm9/main @ 0x020AE9F0; symbol: func_020ae9f0; size: 0x50.
    void Zone3D_ApplyMappedTripleInstanceVisibility(){
        unsigned char *p=GameState_GetSerializedProgressState();
        for(int i=0;i<8;i++)Zone3D_UpdateThreeIndexedInstancesInMatchingZone(i,BitArray_ReadNonnegativeIndexMask(p,p+140,Zone3DApplyMappedTripleInstanceVisibility_UnknownRoleInitializedBytes[i]));
    }
}
