#include <globaldefs.h>
ARM
extern "C" void PopulateOwnerThresholdSlotsAndResourceText(void *object, unsigned int mode);
extern "C" void Menu_QueueScriptEntry(void *state, unsigned int value);
// Original: arm9/ov004 @ 0x021684B0; symbol: func_ov004_021684b0; size: 0x24.
extern "C" int InitializeObjectAndSetState141(void *object) {
    PopulateOwnerThresholdSlotsAndResourceText(object, 0);
    Menu_QueueScriptEntry(object, 0x8d);
    return 0;
}
