#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02058658; symbol: func_02058658; size: 0x28.
extern "C" unsigned char* GetRecordForObjectIndex208Through223(unsigned char* p,int index) { int i=index-0xd0; if (i<0 || i>=16) return 0; return p+8+i*0xd4; }
