#include <globaldefs.h>
#include <Graphics/VRAMStaging.h>
extern "C" {
    unsigned int Object_ReadHalfProductOfTwoNestedBytes(void *);
    extern VRAMSubregion data_020ee950[];
// Original: arm9/main @ 0x020E23F4; symbol: func_020e23f4; size: 0x84.
    void Graphics_StagePresentResourceRegion(unsigned char **p){
        if(!p[1]||!p[0])return;
        p[1][63]=(p[1][63]&~1)|1;
        unsigned char *entry=p[1];
        unsigned int offset=*(unsigned int *)(entry+48);
        unsigned int length=Object_ReadHalfProductOfTwoNestedBytes(entry);
        StageMemoryToVRAM(data_020ee950[entry[62]],p[0]+offset,offset,*(unsigned int *)(entry+52)+length,true,false);
    }
}
