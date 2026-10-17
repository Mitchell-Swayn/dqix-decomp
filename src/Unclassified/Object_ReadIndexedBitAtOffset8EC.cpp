#include <globaldefs.h>
// Original: arm9/main @ 0x02083B00; symbol: func_02083b00; size: 0x28.
extern "C" ARM int Object_ReadIndexedBitAtOffset8EC(unsigned char* state,int bit) { unsigned char* byte=state+bit/8; unsigned shift=bit%8; unsigned value=byte[0x8ec]; unsigned mask=1; mask<<=shift; return value&mask; }
