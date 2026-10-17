#include <globaldefs.h>
extern "C" {
extern unsigned char data_020ee748[];
// Original: arm9/main @ 0x020DD11C; symbol: func_020dd11c; size: 0x38.
unsigned char Lookup_ReadThirteenByFiveByteTable(unsigned int a,unsigned int b){if(a==0||a>=13)return 0;if(b>=5)return 0;return *(data_020ee748+a*5+b);}
}
