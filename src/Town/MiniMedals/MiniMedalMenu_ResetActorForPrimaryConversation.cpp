#include <globaldefs.h>
ARM
extern "C" void MiniMedalMenu_ResetActorToStandingPose(void *);
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x02167D70; symbol: Object_InitializeEntry67AndSetStateTwo; size: 0x20.
// Initializes active entry 0x67 on the supplied object, then selects state 2.
extern "C" int MiniMedalMenu_ResetActorForPrimaryConversation(void *object) {
    MiniMedalMenu_ResetActorToStandingPose(object);
    Menu_QueueScriptEntry(object, 2);
    return 0;
}
