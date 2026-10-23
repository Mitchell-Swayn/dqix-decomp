#include <globaldefs.h>
ARM
#pragma force_active on
extern "C" void Graphics_ResetSharedSceneState(void);
extern "C" void FieldEvent_ReleaseResourcesAndResumeFieldControl(void*);
// Original: arm9/ov001 @ 0x02156558; symbol: Event_ResetMessageDisplayAndCompleteScene; size 0x24.
extern "C" unsigned short Event_ResetMessageDisplayAndCompleteScene(void* object) {
 Graphics_ResetSharedSceneState();
 FieldEvent_ReleaseResourcesAndResumeFieldControl(object);
 *(unsigned char*)((char*)object+1)=1;
 return *(unsigned short*)((char*)object+0xa);
}
#pragma force_active off
