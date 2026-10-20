#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x020DAA20; symbol: func_020daa20; size: 0x38.
char *ActorEffectLoader_FindFreeRequest(char *p){p+=20;for(unsigned char i=0;i<4;i++,p+=12)if(*(int *)(p+8)==-1)return p;return 0;}
}
