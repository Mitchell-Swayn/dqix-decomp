#include <globaldefs.h>
ARM
struct Entry{unsigned char pad[0x2c];unsigned char active;unsigned char tail[0x17];};extern "C" {extern Entry data_0210f3e4[];void ResourceEntry_SetTimedStatusOrRelease(Entry*,int);
// Original: arm9/main @ 0x020BC028; symbol: func_020bc028; size: 0x40.
void ResourceManager_UpdateSixteenActiveEntries(int value){int i;Entry* p=data_0210f3e4;i=0;do{if(p->active)ResourceEntry_SetTimedStatusOrRelease(p,value);i++;p++;}while(i<16);}}
