#include <globaldefs.h>
extern "C" {
extern unsigned int data_020e88d0[];
// Original: arm9/main @ 0x02074948; symbol: func_02074948; size: 0x20.
unsigned int ReadClampedFiveEntryLookupTable(int i){if(i<0)i=0;if(i>4)i=4;return data_020e88d0[i];}
}
