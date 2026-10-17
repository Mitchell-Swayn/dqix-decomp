#include <globaldefs.h>
// Original: arm9/main @ 0x020CF7E4; symbol: func_020cf7e4; size: 0x70.
extern "C" ARM int DecodeValidatedEightDigitPackedDecimal(unsigned packed) { int result=0; int i=0,shift=0; do { if(((packed>>shift)&15)>=10) return 0; ++i; shift+=4; } while(i<8); int scale; int bits; int digit=0; bits=0; scale=1; do { result+=scale*((packed>>bits)&15); ++digit; bits+=4; scale*=10; } while(digit<8); return result; }
