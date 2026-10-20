#include <globaldefs.h>
extern "C" void ZoneState_ResetFourTrackedZones(void*);
// Original: arm9/main @ 0x02028894; symbol: func_02028894; size: 0x4C.
extern "C" void ZoneState_InitializeTrackedZonesWithAllocatorPairs(char* p,char* a,char* b) { ZoneState_ResetFourTrackedZones(p); for(int i=0;i<4;i++){ *(char**)(p+i*0x318+16)=a+i*20; *(char**)(p+i*0x318+20)=b+i*20; } }
