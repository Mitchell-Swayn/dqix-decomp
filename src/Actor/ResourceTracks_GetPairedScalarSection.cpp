#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
unsigned int *ResourceTracks_GetResolvedResourceTable();
// Original: arm9/main @ 0x02055120; symbol: func_02055120; size: 0x18.
unsigned int ResourceTracks_GetPairedScalarSection(){unsigned int *p=ResourceTracks_GetResolvedResourceTable();unsigned int v;if(p==0)v=0;else v=p[6];return v;}
}
