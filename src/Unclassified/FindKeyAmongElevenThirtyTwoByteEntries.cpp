#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02083554; symbol: func_02083554; size: 0x38.
char *FindKeyAmongElevenThirtyTwoByteEntries(char *p,int key){for(int i=0;i<11;i++)if(*(short *)(p+i*32+0x1ac)==key)return p+0x194+i*32;return 0;}
}
