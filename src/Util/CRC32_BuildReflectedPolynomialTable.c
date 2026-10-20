#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020D1C24; symbol: func_020d1c24; size: 0x40.
void CRC32_BuildReflectedPolynomialTable(unsigned *table,unsigned polynomial) { unsigned value,i=0,j; do { value=i; j=0; do { if(value&1)value=polynomial^(value>>1); else value>>=1; ++j; } while(j<8); table[i]=value; ++i; } while(i<256); }
