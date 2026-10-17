#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" unsigned char data_02153694[];extern "C" void* ResolveIndexedRecordAndReturnSecondWord(void*,unsigned);
// Original: arm9/main @ 0x020E51CC; symbol: func_020e51cc; size: 0x18.
extern "C" void* LookupGlobalResourceByKey(unsigned key){return ResolveIndexedRecordAndReturnSecondWord(data_02153694,key);}
