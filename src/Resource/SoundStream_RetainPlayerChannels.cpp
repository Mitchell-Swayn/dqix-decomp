#include <globaldefs.h>
ARM
extern "C" int ResourceEntry_SetValidatedChannelList(void*,int,const unsigned char*);
// Original: arm9/main @ 0x020BF29C; symbol: func_020bf29c; size: 0x38.
extern "C" int SoundStream_RetainPlayerChannels(unsigned char* object,int count,const unsigned char* values){if(!*(int*)(object+0x120) && !ResourceEntry_SetValidatedChannelList(object,count,values))return 0;(*(int*)(object+0x120))++;return 1;}
