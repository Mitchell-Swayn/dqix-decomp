#include <globaldefs.h>
#include <std_library_functions.h>
#include <Graphics/VRAMStaging.h>
#include <Graphics/VRAMAllocations.h>
#include <System/VRAM.h>
extern "C" {
// Original: arm9/main @ 0x02097B34; symbol: func_02097b34; size: 0x90.
void Graphics_ApplyVRAMMappingsUnderTextureLock(unsigned int *p){LockStagedTextureVRAMCopying();if(*(unsigned char *)((char *)p+30)&1){MapVRAMBanksToTextureImage(p[0]);MapVRAMBanksToTexturePalette(p[1]);MapVRAMBanksToMainBG(p[2]);MapVRAMBanksToMainObj(p[3]);unsigned short count=0;for(unsigned int bits=p[0];bits;bits&=bits-1)count++;InitializeTextureImageVRAM(count,true);}if(*(unsigned char *)((char *)p+30)&2){MapVRAMBanksToSubBG(p[4]);MapVRAMBanksToSubObj(p[5]);}UpdateVRAMStagingVRAMBanks();UnlockStagedTextureVRAMCopying();}
}
