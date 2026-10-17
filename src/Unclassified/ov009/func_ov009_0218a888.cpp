#include <globaldefs.h>
ARM
// Original: arm9/ov009 @ 0x0218A888; symbol: func_ov009_0218a888; size: 0x30.
extern "C" int func_ov009_0218a888(void* unused, const unsigned char* bytes, int count, int value) {
 for(int i=0;i<count;i++,bytes++) if(*bytes==value) return 1;
 return 0;
}
