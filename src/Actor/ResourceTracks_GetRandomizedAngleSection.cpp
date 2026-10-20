#include <globaldefs.h>
ARM
extern "C" unsigned char* ResourceTracks_GetResolvedResourceTable();
// Original: arm9/main @ 0x02055150; symbol: func_02055150; size: 0x18.
 extern "C" unsigned int ResourceTracks_GetRandomizedAngleSection() { unsigned char* p=ResourceTracks_GetResolvedResourceTable(); unsigned int result; if (p==0) result=0; else result=*(unsigned int*)(p+0x20); return result; }
