#include <globaldefs.h>
ARM
extern "C" void Resource_ResetActiveOwnerState(unsigned char*);
extern "C" void ResetActiveAllocationTextResources(void*);
extern "C" void RefreshFlaggedCanvasAndSubmitCoordinates(void*);
extern "C" void PartyGrowthPanel_ResetActiveWindowTransfers(void*);
extern "C" void ResetStateEntryResources(void*);
// Original: arm9/ov000 @ 0x02160AD0; symbol: ResetPresentStateResources; size: 0x84.
// Resets present state resources, preferring the two linked owner fields.
extern "C" void ResetPresentStateResources(unsigned char* p) {
 if (!*(int*)(p+0x55f8)) return;
 if (*(void**)(p+0x55cc)) Resource_ResetActiveOwnerState(*(unsigned char**)(p+0x55cc));
 if (*(void**)(p+0x5574)) {
  ResetActiveAllocationTextResources(*(void**)(p+0x5574));
  if (*(void**)(p+0x5578)) RefreshFlaggedCanvasAndSubmitCoordinates(*(void**)(p+0x5578));
 } else if (*(void**)(p+0x5588)) PartyGrowthPanel_ResetActiveWindowTransfers(*(void**)(p+0x5588));
 else if (!(*(unsigned*)(p+0x55f4)&0x40000)) ResetStateEntryResources(p+0x3760);
}
