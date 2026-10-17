#include <globaldefs.h>
struct Map { char pad[0x41b]; unsigned char bits[1]; };
// Original: arm9/main @ 0x0206EAEC; symbol: func_0206eaec; size: 0x34.
extern "C" bool BitMap_ReadReversedColumnBit(Map* p,int row,int col) { p=(Map*)((char*)p+row*32); short index=col>>3; unsigned short shift=(col&7)^7; return (p->bits[index]>>shift)&1; }
