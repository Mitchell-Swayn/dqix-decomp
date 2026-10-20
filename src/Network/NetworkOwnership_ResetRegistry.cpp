#include <globaldefs.h>
#pragma optimization_level 2
ARM
#pragma optimize_for_size off
extern "C" void NetworkOwnership_ClearEntry(void*);
// Original: arm9/main @ 0x020E3004; symbol: func_020e3004; size: 0x38.
extern "C" void NetworkOwnership_ResetRegistry(char* p){char* flags=p+32;int i=0;while(i<8){NetworkOwnership_ClearEntry(p);*flags=0;i++;p+=4;flags++;}}
