#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x020A28E0; symbol: func_020a28e0; size: 0x28.
void InvalidateByte270AndClearSixWords(char *p){p[0x270]=-1;*(int *)(p+0x274)=0;*(int *)(p+0x278)=0;*(int *)(p+0x27c)=0;*(int *)(p+0x280)=0;*(int *)(p+0x284)=0;*(int *)(p+0x288)=0;}
}
