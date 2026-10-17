#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void InitializeThirtyTwoRecordsAndOwnerCounters(void*);
// Original: arm9/main @ 0x0203BD78; symbol: func_0203bd78; size: 0x10.
extern "C" void ResetEmbeddedRecordAt10(unsigned char* p){InitializeThirtyTwoRecordsAndOwnerCounters(p+16);}
