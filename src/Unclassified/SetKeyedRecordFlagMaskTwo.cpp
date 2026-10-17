#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void SetResolvedEntryByte2ABits(void*,int,unsigned);
// Original: arm9/main @ 0x020806B0; symbol: func_020806b0; size: 0x14.
extern "C" void SetKeyedRecordFlagMaskTwo(unsigned char* p,int key){SetResolvedEntryByte2ABits(p+4,key,2);}
