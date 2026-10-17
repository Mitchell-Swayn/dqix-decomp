#include <globaldefs.h>
#include <World/ZonePredicates.h>
extern "C" unsigned short* ReadGlobalValueAt020FB3F0();
extern "C" void Object_SetByteBEAndSavePreviousInBF(void*,unsigned);
extern "C" void Object_InvokeStateMethodAndRecordSuccessfulTransition(void*,unsigned);
struct FloorObject { char pad[0x14c];unsigned floor; };
// Original: arm9/main @ 0x02076D5C; symbol: func_02076d5c; size: 0x44.
extern "C" void ProcessHighFloorOrGrottoBossFloorObject(FloorObject* p) {if(!IsGrottoBossFloorZone(*ReadGlobalValueAt020FB3F0()) && p->floor<=1000)return;Object_SetByteBEAndSavePreviousInBF(p,0);Object_InvokeStateMethodAndRecordSuccessfulTransition(p,1);}
