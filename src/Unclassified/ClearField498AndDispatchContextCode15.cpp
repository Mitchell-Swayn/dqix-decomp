#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" bool FindGroupAndProcessHeadAfterClearingOutputCount(void*,unsigned,void*);
// Original: arm9/main @ 0x02064A08; symbol: func_02064a08; size: 0x1C.
extern "C" bool ClearField498AndDispatchContextCode15(unsigned char* p,void* context){*(int*)(p+0x498)=0;return FindGroupAndProcessHeadAfterClearingOutputCount(p,15,context);}
