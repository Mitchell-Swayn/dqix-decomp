#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02053604; symbol: func_02053604; size: 0x30.
extern "C" int GameObject_GetCurrentQueuedActionOrInvalid(signed char* p) { if(!p[0x17c])return -1;int i=p[0x17d];if(i>=4)return -1;signed char* entry=p+i;return entry[0x178]; }
