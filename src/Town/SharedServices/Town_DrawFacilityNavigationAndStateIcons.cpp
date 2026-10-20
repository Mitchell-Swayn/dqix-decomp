#include <globaldefs.h>
ARM
extern "C" void* NavigationMessage_GetGlobalInstance(void);
extern "C" void NavigationMessage_DrawForCurrentState(void*);
extern "C" void TagMode_DrawCancelButton(void*);
extern "C" void Resource_ConfigureIndexedObjectEffectRecord(void*);
// Original: arm9/ov003 @ 0x02173EA8; symbol: ProcessDisplayResourceStateWhenEligible; size: 0x4C.
// Dispatches global display resource updates, then runs both record handlers unless state +0xEC is 0 or 6, or state is 1 with byte +0xEE below 2.
extern "C" void Town_DrawFacilityNavigationAndStateIcons(void* self) {
    void* manager = NavigationMessage_GetGlobalInstance();
    NavigationMessage_DrawForCurrentState(manager);
    unsigned char state = *((unsigned char*)self + 0xEC);
    if (state == 0) return;
    if (state == 1 && *((unsigned char*)self + 0xEE) < 2) return;
    if (state == 6) return;
    TagMode_DrawCancelButton(self);
    Resource_ConfigureIndexedObjectEffectRecord(self);
}
