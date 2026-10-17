#include <globaldefs.h>
struct Entry {unsigned short unknown;unsigned char flags;char pad[17];};extern "C" Entry data_020fdc60[4];
// Original: arm9/main @ 0x0202738C; symbol: func_0202738c; size: 0xAC.
extern "C" void WriteMatchingSlotFlagMask(char* self,int enabled,unsigned char mask,int wanted) {if(wanted<0){Entry* entry;for(int i=0;i<4;++i){entry=data_020fdc60+i;unsigned flags=entry->flags;if(enabled)flags|=mask;else flags &= ~mask;entry->flags=flags;}return;}if(wanted>=4)return;for(int i=0;i<4;++i){Entry* entry=data_020fdc60+i;if(wanted==(unsigned char)(self+i)[0x758]){if(enabled){entry->flags|=mask;return;}else {entry->flags &=~mask;return;}}}}
