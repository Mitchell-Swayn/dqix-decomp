#include <globaldefs.h>
extern "C" {unsigned int *ResourceTracks_GetResolvedResourceTable();
// Original: arm9/main @ 0x02055090; symbol: func_02055090; size: 0x18.
unsigned int ResourceTracks_GetLargePayloadSection(){unsigned int *p=ResourceTracks_GetResolvedResourceTable();return p==0?0:*p;}}
