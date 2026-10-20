#include <globaldefs.h>
ARM
extern "C" void PopulateOwnerThresholdSlotsAndResourceText(void *, unsigned int);
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x02167FB0; symbol: InitializeObjectAndSetState51; size: 0x24.
// Runs the object setup helper with zero, then stores state value 0x33.
extern "C" int MiniMedalMenu_PrepareExchangeContinuationText(void *self) {
    PopulateOwnerThresholdSlotsAndResourceText(self, 0);
    Menu_QueueScriptEntry(self, 0x33);
    return 0;
}
