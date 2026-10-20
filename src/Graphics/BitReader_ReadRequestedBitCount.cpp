#include <globaldefs.h>
ARM
struct BitReader { unsigned char *cursor; signed char remaining; unsigned char bits; };
// Original: arm9/main @ 0x020B29F8; symbol: func_020b29f8; size: 0x60.
extern "C" unsigned BitReader_ReadRequestedBitCount(BitReader *self,int count) { int remaining=self->remaining; unsigned char bits=self->bits; unsigned value; if(remaining<count) { self->bits=*self->cursor++; self->remaining=8; value=BitReader_ReadRequestedBitCount(self,count-remaining); value|=(unsigned)bits<<(count-remaining); } else { value=(unsigned)bits>>(remaining-count); self->remaining=remaining-count; } return value&(255>>(8-count)); }
