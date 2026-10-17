#include <globaldefs.h>
extern "C" {
extern unsigned int data_020e9200[][4];
// Original: arm9/main @ 0x020B11AC; symbol: func_020b11ac; size: 0x1C.
unsigned int ReadByteIndexedTwoDimensionalLookup(unsigned char *p){return data_020e9200[p[1]][p[0]];}
}
