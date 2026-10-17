#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x0204F160; symbol: func_0204f160; size: 0x14.
void SetWordAndByteFieldsUnlessFlagBitZeroSet(char *p,unsigned int v,unsigned char b){if(!(*(unsigned char *)(p+0xc5)&1)){*(unsigned int *)(p+0xa0)=v;*(unsigned char *)(p+0xc4)=b;}}
}
