#include <globaldefs.h>
ARM
extern "C" {
}
// Original: arm9/ov023 @ 0x021F9B30; symbol: func_ov023_021f9b30; size: 0x3C.
// Field roles beyond the stated offset operations remain uncertain.
extern "C" int WriteBoundedHalfwordGridCell(char* p,int v,unsigned x,unsigned y) {
    unsigned short* cells=*(unsigned short**)(p+32);
    if(!cells)return 0;
    if(*(unsigned short*)(p+36)<=x||*(unsigned short*)(p+38)<=y)return 0;
    cells[x**(unsigned short*)(p+38)+y]=v;
    return 1;
}
