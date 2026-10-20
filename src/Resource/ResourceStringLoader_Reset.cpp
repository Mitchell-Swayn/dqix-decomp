#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
void BackgroundLoader_CancelTaskAndResetCountAndValue(void *);
// Original: arm9/main @ 0x020DFC40; symbol: func_020dfc40; size: 0x2C.
void ResourceStringLoader_Reset(char *p){memset(p,0,12);*(short *)(p+12)=-1;*(int *)(p+16)=-1;BackgroundLoader_CancelTaskAndResetCountAndValue(p);}
}
