#include <globaldefs.h>
ARM
extern "C" void* data_020fe9a4;extern "C" void LoadToMainBG1CharacterData(const void*,unsigned int,unsigned int);extern "C" void LoadToSubBG0CharacterData(const void*,unsigned int,unsigned int);
// Original: arm9/main @ 0x020290AC; symbol: func_020290ac; size: 0x3C.
extern "C" void Graphics_UploadMainOrSubBackgroundCharacterBuffer(int sub) { void* p=data_020fe9a4;if(!p)return;if(!sub)LoadToMainBG1CharacterData(p,0,0x6000);else LoadToSubBG0CharacterData(p,0,0x6000); }
