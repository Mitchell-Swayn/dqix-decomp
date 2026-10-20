#include <globaldefs.h>
ARM
extern "C" void* SystemState_GetGlobalFlags();
extern "C" bool SystemState_TestAnyFlags(const unsigned int*,unsigned int);
extern "C" void WorldMap_AdvanceZoneMapLoad(char*);
extern "C" void WorldMap_AdvanceTreasureMapEntranceLoad(char*);
extern "C" void SubMapDisplay_AdvanceTmapResourceLoad(char*);
extern "C" void WorldMap_AdvanceGrottoFloorMapLoad(char*);
extern "C" void BackgroundLoader_AdvanceQueuedGraphicsLoadState(char*);
// Original: arm9/main @ 0x020214F0; symbol: BackgroundLoader_DispatchEnabledState; size: 0x88.
// Dispatches the enabled loader state unless global mask 0x41 inhibits it.
extern "C" void BackgroundLoader_DispatchEnabledState(char* self) {
 if (!*(unsigned char*)(self+0x9c3)) return;
 if (SystemState_TestAnyFlags((const unsigned int*)SystemState_GetGlobalFlags(),0x41)) return;
 switch (*(unsigned char*)(self+0x9c1)) {
 case 0: WorldMap_AdvanceZoneMapLoad(self); break;
 case 1: WorldMap_AdvanceTreasureMapEntranceLoad(self); break;
 case 2: SubMapDisplay_AdvanceTmapResourceLoad(self); break;
 case 3: WorldMap_AdvanceGrottoFloorMapLoad(self); break;
 case 4: BackgroundLoader_AdvanceQueuedGraphicsLoadState(self); break;
 }
}
