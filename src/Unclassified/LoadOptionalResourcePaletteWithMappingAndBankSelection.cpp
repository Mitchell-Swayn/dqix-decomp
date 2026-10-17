#include <globaldefs.h>

ARM
extern "C" {
void ResetThreeSlotIndicesToMinusOne(void *);
int ParsePMCPResourceBlock(void *,void **);int ResourceFile_FindAndRelocateTTLPChunk(void *,void **);
void Graphics_LoadPaletteToSelectedVRAMBank(void *,unsigned,int,void *);
void CopySelectedFormattedResourceBlocks(void *,void *,unsigned,int,void *);
// Original: arm9/main @ 0x0205AB78; symbol: func_0205ab78; size: 0xC8.
int LoadOptionalResourcePaletteWithMappingAndBankSelection(unsigned char *p,void *resource,int enabled) {
    ResetThreeSlotIndicesToMinusOne(p+0x24);
    void *palette=0; void *mapping=0;
    int compressed=ParsePMCPResourceBlock(resource,&mapping);
    bool invalid;
    if(resource==0)invalid=true;
    else if(enabled==0)invalid=true;
    else if(ResourceFile_FindAndRelocateTTLPChunk(resource,&palette) != 0) invalid=false;
    else invalid=true;
    if(invalid)return 1;
    int bank=p[0x50]==0?1:2;
    if(compressed)CopySelectedFormattedResourceBlocks(palette,mapping,0,bank,p+0x24);
    else Graphics_LoadPaletteToSelectedVRAMBank(palette,0,bank,p+0x24);
    return 0;
}
}
