#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02032E24; symbol: func_02032e24; size: 0x34.
extern "C" unsigned FindHalfwordValueByKeyOrReturnFullWidthSpace(unsigned key,unsigned short* entries,int count){++count;while(count--!=0){if(entries[1]==key)return entries[0];entries+=2;}return 0x8140;}
