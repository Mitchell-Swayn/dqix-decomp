#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x0206F510; symbol: func_0206f510; size: 0x40.
void Script_ResetFacilityCommandContext(char *p){memset(p,0,4);*(int *)(p+4)=0;memset(p+8,-1,8);memset(p+16,0,32);}
}
