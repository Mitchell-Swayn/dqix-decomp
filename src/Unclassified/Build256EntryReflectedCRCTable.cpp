#include <globaldefs.h>
// Original: arm9/main @ 0x020D1BA0; symbol: func_020d1ba0; size: 0x44.
extern "C" ARM void Build256EntryReflectedCRCTable(unsigned short* table,unsigned polynomial){unsigned v;unsigned index=0;do{v=index;unsigned bit=0;do{if(v&1)v=polynomial^(v>>1);else v>>=1;++bit;}while(bit<8);table[index]=v;++index;}while(index<256);}
