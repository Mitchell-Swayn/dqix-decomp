#include <globaldefs.h>
ARM
#include <System/LoadToVRAM.h>
extern "C" void* memset(void*,int,unsigned);
extern unsigned char data_021065d8[],data_02105fd8[];
// Original: arm9/main @ 0x0203B678; symbol: func_0203b678; size: 0xA0.
extern "C" void Graphics_ClearSubBackgroundCharacterBuffers(int* object,int screen,int layer){unsigned char zero[32];object[screen]=32;*(int*)((char*)(object+screen)+0x20)=1;memset(zero,0,32);if(screen==1){switch(layer){case 0:memset(data_021065d8,0,0x1000);LoadToSubBG0CharacterData(zero,0,32);break;case 1:memset(data_02105fd8,0,0x600);LoadToSubBG1CharacterData(zero,0,32);break;}}}
