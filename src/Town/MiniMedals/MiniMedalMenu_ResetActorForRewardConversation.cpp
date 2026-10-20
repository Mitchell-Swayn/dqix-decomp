#include <globaldefs.h>
ARM
extern "C" void MiniMedalMenu_ResetActorToStandingPose(void *);
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x021683CC; symbol: func_ov004_021683cc; size: 0x20.
extern "C" int MiniMedalMenu_ResetActorForRewardConversation(void *object) {
    MiniMedalMenu_ResetActorToStandingPose(object);
    Menu_QueueScriptEntry(object, 2);
    return 0;
}
