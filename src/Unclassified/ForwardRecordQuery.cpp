#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int ClearActiveHalfwordsAndCancelStoredId(void*);
// Original: arm9/main @ 0x020D68D0; symbol: func_020d68d0; size: 0xC.
extern "C" int ForwardRecordQuery(void* p){return ClearActiveHalfwordsAndCancelStoredId(p);}
