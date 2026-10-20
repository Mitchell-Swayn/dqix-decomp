#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0202BCF8; symbol: func_0202bcf8; size: 0x3C.
extern "C" int Network_FindPreviousWirelessSlotByMemberId(signed char* p,int value) { int i=0;while(i<16) { signed char* entry=p+i;if(value==entry[0x1048])break;++i; }return i==16 ? -1 : (signed char)i; }
