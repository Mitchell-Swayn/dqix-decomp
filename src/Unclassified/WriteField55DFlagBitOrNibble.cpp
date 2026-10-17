#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x02020028; symbol: func_02020028; size: 0x44.
void WriteField55DFlagBitOrNibble(unsigned char *p,int set,int i){if(i<0){if(set)p[0x55d]=15;else p[0x55d]=0;}else{if(set)p[0x55d]|=1<<i;else p[0x55d]&=~(1<<i);}}
}
