#include <globaldefs.h>
#include <Graphics/VRAMStaging.h>
#include <Graphics/VRAMAllocations.h>
#include <System/VRAM.h>
// Original: arm9/main @ 0x02097C18; symbol: func_02097c18; size: 0x94.
extern "C" void VRAMBankConfig_ApplyMappings(char* self,unsigned char flags,unsigned texture,unsigned palette,unsigned mainBG,unsigned mainObj,unsigned subBG,unsigned subObj) {LockStagedTextureVRAMCopying();self[0x1e]=flags;if(flags&1){MapVRAMBanksToTextureImage(texture);MapVRAMBanksToTexturePalette(palette);MapVRAMBanksToMainBG(mainBG);MapVRAMBanksToMainObj(mainObj);unsigned short count=0;for(;texture;texture&=texture-1)++count;InitializeTextureImageVRAM(count,true);}if(flags&2){MapVRAMBanksToSubBG(subBG);MapVRAMBanksToSubObj(subObj);}UpdateVRAMStagingVRAMBanks();UnlockStagedTextureVRAMCopying();}
