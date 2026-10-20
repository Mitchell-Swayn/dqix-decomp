#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" void ZoneState_ConstructTrackedZoneRecord(void*);
extern "C" void FinalizeEmbeddedObjectsAtOffsets18And60And124And304(void*);
extern "C" void RuntimeArrays_ConstructElementsWithRollback(void*,unsigned,unsigned,void(*)(void*),void(*)(void*));
extern "C" void ZoneState_ResetFourTrackedZones(void*);
// Original: arm9/main @ 0x02028C8C; symbol: func_02028c8c; size: 0x40.
extern "C" void* ZoneState_ConstructTrackedZoneCache(void* p){
    RuntimeArrays_ConstructElementsWithRollback(p,4,0x318,ZoneState_ConstructTrackedZoneRecord,FinalizeEmbeddedObjectsAtOffsets18And60And124And304);
    ZoneState_ResetFourTrackedZones(p);
    return p;
}
