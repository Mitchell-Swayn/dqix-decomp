#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x0205C710; symbol: func_0205c710; size: 0x2C.
unsigned int ReadValueFromEnabledPrimaryOrSecondarySelection(unsigned char *p){unsigned int v=0;if(p[0x94]&&p[0x50])v=*(unsigned int *)(p+24);if(p[0x95])v=*(unsigned int *)(p+0x68);return v;}
}
