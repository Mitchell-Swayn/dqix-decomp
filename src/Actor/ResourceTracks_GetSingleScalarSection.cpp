#include <globaldefs.h>
extern "C" {
unsigned int *ResourceTracks_GetResolvedResourceTable();
// Original: arm9/main @ 0x020550C0; symbol: func_020550c0; size: 0x18.
unsigned int ResourceTracks_GetSingleScalarSection(){unsigned int *p=ResourceTracks_GetResolvedResourceTable();unsigned int result;if(p==0)result=0;else result=p[2];return result;}
}
