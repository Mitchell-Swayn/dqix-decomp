#include <globaldefs.h>
THUMB
// Original: arm9/ov031 @ 0x0221E31C; symbol: func_ov031_0221e31c; size: 0x38.
// Generates 256 reflected CRC-32 table entries using polynomial 0xedb88320 and returns the generated entry count.
// The incoming first argument is ignored; its register becomes the entry counter.
extern "C" int InitializeReflectedCRC32Table(int unused,unsigned* table) {
 unsigned value;
 int bit;
 unused=0; do {
  value=unused;
  bit=0; do {
   if(value&1)value=(value>>1)^0xedb88320;
   else value>>=1;
  } while(++bit<8);
  ++unused;
  *table++=value;
 } while(unused<256);
 return unused;
}
