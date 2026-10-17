#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
void SetMaskedFlagsAtOffset910(void *,unsigned char);
// Original: arm9/main @ 0x02083B8C; symbol: func_02083b8c; size: 0x34.
void Object_ApplyEachInputIdentifier(void *p,unsigned char *q,unsigned int n){for(unsigned int i=0;i<n;i++)SetMaskedFlagsAtOffset910(p,q[i]);}
}
