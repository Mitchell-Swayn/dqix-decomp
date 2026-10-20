#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x022155E8; symbol: func_ov031_022155e8; size: 0x54.
// Packs four bytes most-significant first, then reverses the packed byte order.
extern "C" unsigned Util_ReadFourBytesAndReversePackedWord(const unsigned char *bytes) {
 unsigned word=0;
 word|=(unsigned)bytes[0]<<24;
 word|=(unsigned)bytes[1]<<16;
 word|=(unsigned)bytes[2]<<8;
 word|=bytes[3];
 return ((word>>24)&255)|((word>>8)&0xff00)|((word<<8)&0xff0000)|((word<<24)&0xff000000);
}
