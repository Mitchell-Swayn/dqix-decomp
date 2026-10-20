#include <globaldefs.h>
#include <Graphics/VRAMStaging.h>
extern "C" {
    unsigned int Window_GetFillPatternByteSize(void *);
// Original data: arm9/main @ 0x20ee950; symbol: data_020ee950.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1500000017000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern VRAMSubregion GraphicsStagePresentResourceRegion_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x020E23F4; symbol: func_020e23f4; size: 0x84.
    void Graphics_StagePresentResourceRegion(unsigned char **p){
        if(!p[1]||!p[0])return;
        p[1][63]=(p[1][63]&~1)|1;
        unsigned char *entry=p[1];
        unsigned int offset=*(unsigned int *)(entry+48);
        unsigned int length=Window_GetFillPatternByteSize(entry);
        StageMemoryToVRAM(GraphicsStagePresentResourceRegion_UnknownRoleInitializedBytes[entry[62]],p[0]+offset,offset,*(unsigned int *)(entry+52)+length,true,false);
    }
}
