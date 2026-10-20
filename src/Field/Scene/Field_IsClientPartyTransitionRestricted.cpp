#include <globaldefs.h>
#include <Resource/GameResources.h>
#pragma force_active on
ARM
extern "C" GameResources* GameResources_GetInstance();
extern "C" void* Network_GetConnectionManager();
extern "C" bool Network_IsClientSession(unsigned int*);
extern "C" int FieldEvent_IsQueuedOrSynchronizing(unsigned char*);
struct TransitionFlags { unsigned int value:27; unsigned int high:5; };
// Original: arm9/ov017 @ 0x021925E0; symbol: func_ov017_021925e0; size: 0x74.
// Reports the client-side party transition restriction from queued event state and control flags.
extern "C" int Field_IsClientPartyTransitionRestricted()
{
    unsigned char* event=*(unsigned char**)((unsigned char*)GameResources_GetInstance()+0x3734);
    if (Network_IsClientSession((unsigned int*)Network_GetConnectionManager())) {
        if (FieldEvent_IsQueuedOrSynchronizing(event) && event[0x101]) {
            if ((!event[0x101] || !(((TransitionFlags*)(event+0xf8))->value&4)) && !event[0xff] && event[0xcf]!=2) return 1;
        }
    }
    return 0;
}
