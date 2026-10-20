#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x02096100; symbol: func_02096100; size: 0x34.
unsigned int Quest_TestBoundedIdFlag(int unused,unsigned char *p,int i){if(i>204||i<0)return 0;unsigned char mask=1<<(i&7);return p[i>>3]&mask;}
}
