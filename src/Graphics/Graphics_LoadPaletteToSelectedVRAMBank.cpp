#include <globaldefs.h>
#include <System/Cache.h>
#include <System/LoadToVRAM.h>
struct Palette {unsigned kind,extended,size;const void* data;};
struct PaletteHandle {unsigned kind,extended;};
extern "C" void NNS_G2dSetImagePaletteLocation(PaletteHandle*,int,unsigned,unsigned);
// Original: arm9/main @ 0x020B07C0; symbol: func_020b07c0; size: 0xF8.
extern "C" void Graphics_LoadPaletteToSelectedVRAMBank(Palette* p,unsigned offset,int bank,PaletteHandle* output){const void* data=p->data;unsigned size=p->size;CleanInvalidateCacheRange(data,size);switch(bank){case 1:if(p->extended){MemoryMapMainObjExtendedPalette();LoadToMainObjExtendedPalette(data,offset,size);MemoryUnmapMainObjExtendedPalette();}else LoadToMainObjStandardPalette(data,offset,size);break;case 2:if(p->extended){MemoryMapSubObjExtendedPalette();LoadToSubObjExtendedPalette(data,offset,size);MemoryUnmapSubObjExtendedPalette();}else LoadToSubObjStandardPalette(data,offset,size);break;case 0:MemoryMapTexturePalette();LoadToTexturePalette(data,offset,size);MemoryUnmapTexturePalette();break;}output->kind=p->kind;unsigned extended=p->extended;output->extended=extended;NNS_G2dSetImagePaletteLocation(output,bank,offset,extended);}
