#include <globaldefs.h>
ARM
extern "C" void* data_020fe9a4;extern "C" char data_020ef74c[];extern "C" void* memset(void*,int,unsigned);extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);extern "C" void LoadToMainBG1CharacterData(const void*,unsigned,unsigned);extern "C" void LoadToSubBG0CharacterData(const void*,unsigned,unsigned);
// Original: arm9/main @ 0x02028E90; symbol: func_02028e90; size: 0xC4.
extern "C" void Graphics_ClearBufferAndUploadCharacterDataByMode(){void* p=data_020fe9a4;if(!p)return;if(p)memset(p,0,24576);int mode=*(int*)(data_020ef74c+12);_Z25CleanInvalidateCacheRangePKvj(data_020fe9a4,24576);if(mode==3){LoadToMainBG1CharacterData(data_020fe9a4,0,24576);return;}if(mode==4){LoadToSubBG0CharacterData(data_020fe9a4,0,24576);return;}if(mode==5){LoadToMainBG1CharacterData(data_020fe9a4,0,24576);return;}if(mode==6)LoadToSubBG0CharacterData(data_020fe9a4,0,24576);}
