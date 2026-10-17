#include <globaldefs.h>
// Original: arm9/main @ 0x0206E120; symbol: func_0206e120; size: 0x44.
extern "C" ARM int ReadOneOf204PackedTwoBitValues(volatile unsigned char* self,int index){if(index>=204 || index<0)return 0;int odd=index%2;index=index/2;self+=index;if(odd)return (self[716]>>4)&3;else return self[716]&3;}
