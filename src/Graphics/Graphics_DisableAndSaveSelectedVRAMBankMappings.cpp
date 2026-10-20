#include <globaldefs.h>
ARM
extern "C" unsigned DisableTextureImageVRAMBanks();extern "C" unsigned DisableTexturePaletteVRAMBanks();extern "C" unsigned DisableMainBGVRAMBanks();extern "C" unsigned DisableMainObjVRAMBanks();extern "C" unsigned DisableSubBGVRAMBanks();extern "C" unsigned DisableSubObjVRAMBanks();
// Original: arm9/main @ 0x02097BC4; symbol: func_02097bc4; size: 0x54.
extern "C" void Graphics_DisableAndSaveSelectedVRAMBankMappings(unsigned* p,unsigned flag){*((unsigned char*)p+30)=flag;if(flag&1){p[0]=DisableTextureImageVRAMBanks();p[1]=DisableTexturePaletteVRAMBanks();p[2]=DisableMainBGVRAMBanks();p[3]=DisableMainObjVRAMBanks();}if(flag&2){p[4]=DisableSubBGVRAMBanks();p[5]=DisableSubObjVRAMBanks();}}
