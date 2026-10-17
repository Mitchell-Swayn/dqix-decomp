#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#include <System/Cache.h>
#include <System/LoadToVRAM.h>
struct Counters{unsigned int offsets[8];int counts[8];};
// Original: arm9/main @ 0x0203B784; symbol: func_0203b784; size: 0x138.
extern "C" unsigned int Graphics_AppendAndUploadBackgroundCharacterData(unsigned int* p,int screen,int bg,const void* data,unsigned int size,int count){unsigned int offset=p[screen];p[screen]=offset+size;unsigned int index=((Counters*)p)->counts[screen];(p+8)[screen]+=count;CleanInvalidateCacheRange(data,size);switch(screen){case 0:switch(bg){case 0:LoadToMainBG0CharacterData(data,offset,size);break;case 1:LoadToMainBG1CharacterData(data,offset,size);break;case 2:LoadToMainBG2CharacterData(data,offset,size);break;case 3:LoadToMainBG3CharacterData(data,offset,size);break;}break;case 1:switch(bg){case 0:LoadToSubBG0CharacterData(data,offset,size);break;case 1:LoadToSubBG1CharacterData(data,offset,size);break;case 2:LoadToSubBG2CharacterData(data,offset,size);break;case 3:LoadToSubBG3CharacterData(data,offset,size);break;}break;}return index;}
