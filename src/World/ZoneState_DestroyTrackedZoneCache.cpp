#include <globaldefs.h>
extern "C" void ZoneState_ResetFourTrackedZones(void*);extern "C" void FinalizeEmbeddedObjectsAtOffsets18And60And124And304(void*);extern "C" void __cxa_vec_cleanup(void*,unsigned,unsigned,void(*)(void*));
// Original: arm9/main @ 0x02028D2C; symbol: func_02028d2c; size: 0x2C.
extern "C" ARM void* ZoneState_DestroyTrackedZoneCache(void* p){ZoneState_ResetFourTrackedZones(p);__cxa_vec_cleanup(p,4,0x318,FinalizeEmbeddedObjectsAtOffsets18And60And124And304);return p;}
