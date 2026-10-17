// ARM instruction evidence reviewed; opaque field offsets preserve observed layout.
// Original: arm9/main @ 0x02088644; symbol: func_02088644; size: 0x1C.
extern "C" void ClearWord14Bit1AndHalfword22Bits0And1(char* p) {*(unsigned int*)(p+0x14)&=~2u;*(unsigned short*)(p+0x22)&=~3;}
