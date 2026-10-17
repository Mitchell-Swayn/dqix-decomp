#include <globaldefs.h>
#pragma always_inline on
struct Record {
 unsigned short a,b,c,d,e,f;unsigned g;unsigned char payload[24];
 unsigned h,i;unsigned char j,k;unsigned short values[6];
};
// Original: arm9/main @ 0x020A9304; symbol: func_020a9304; size: 0x98.
extern "C" ARM Record* CopyWholeRecordAndReturnDestination(Record* dst,const Record* src){*dst=*src;return dst;}
