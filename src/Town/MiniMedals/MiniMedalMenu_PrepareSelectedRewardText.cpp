#include <globaldefs.h>
ARM
extern "C" void PopulateOwnerThresholdSlotsAndResourceText(void *, int);
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x02168244; symbol: func_ov004_02168244; size: 0x24.
extern "C" int MiniMedalMenu_PrepareSelectedRewardText(void *object) {
    PopulateOwnerThresholdSlotsAndResourceText(object, 0);
    Menu_QueueScriptEntry(object, 0x96);
    return 0;
}
