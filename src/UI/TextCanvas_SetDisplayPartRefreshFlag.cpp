#include <globaldefs.h>
ARM
extern "C" unsigned char* TextCanvas_FindDisplayPartByKey(void*,int);extern "C" int TextCanvas_CreateAndConfigureDisplayPart(void*,int);
// Original: arm9/main @ 0x02081EA4; symbol: func_02081ea4; size: 0x40.
extern "C" void TextCanvas_SetDisplayPartRefreshFlag(void* p,int key,int enabled){unsigned char* entry=TextCanvas_FindDisplayPartByKey(p,key);if(!entry)return;if(enabled)entry[197]|=64;else entry[197]&=~64;TextCanvas_CreateAndConfigureDisplayPart(p,key);}
