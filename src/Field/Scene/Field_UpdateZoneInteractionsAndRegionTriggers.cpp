#include <globaldefs.h>
ARM
extern "C" char* Zone3D_GetMainInstance();
extern "C" unsigned LinkedQueue_GetFrontNode(void*);
extern "C" void Field_SelectNearbyFacingChest(void*);
extern "C" void Field_BeginLadderTraversalFromPairedFeatures(void*);
extern "C" void Field_SelectAndActivateFacingTypeTwoFeatures(void*);
extern "C" void Field_DispatchZoneRegionEnterAndLeaveTriggers(void*);
extern "C" void Field_ApplyContainingCameraRegion(void*);
extern "C" void Field_SelectContainingTypeFiveInteraction(void*);
extern "C" void World_SelectNearestFacingTypeEightFeature(void*);
extern "C" void Field_SelectMatchingTypeTenInteraction(void*);
extern "C" void Field_CollectNearbyWorldPickup(void*);
extern "C" void Field_ProcessNearbyGrottoEntrance(void*);
extern "C" void Field_DispatchDynamicRegionEnterAndLeaveTriggers(void*);
// Original: arm9/ov017 @ 0x0219755C; symbol: RunUnblockedObjectUpdateSequence; size: 0x88.
// Runs the ordered object update stages when zone424 and record36FC do not inhibit them.
extern "C" void Field_UpdateZoneInteractionsAndRegionTriggers(char* self) {
if(*(unsigned*)(Zone3D_GetMainInstance()+0x424))return;
Field_SelectNearbyFacingChest(self);
if(LinkedQueue_GetFrontNode(*(void**)(self+0x36fc)))return;
Field_BeginLadderTraversalFromPairedFeatures(self);
Field_SelectAndActivateFacingTypeTwoFeatures(self);
Field_DispatchZoneRegionEnterAndLeaveTriggers(self);
Field_ApplyContainingCameraRegion(self);
Field_SelectContainingTypeFiveInteraction(self);
World_SelectNearestFacingTypeEightFeature(self);
Field_SelectMatchingTypeTenInteraction(self);
Field_CollectNearbyWorldPickup(self);
Field_ProcessNearbyGrottoEntrance(self);
Field_DispatchDynamicRegionEnterAndLeaveTriggers(self);
}
