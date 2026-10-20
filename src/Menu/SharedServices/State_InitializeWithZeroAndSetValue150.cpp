#include <globaldefs.h>
ARM
extern "C" void PopulateOwnerThresholdSlotsAndResourceText(void *, int);
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x0216848C; symbol: func_ov004_0216848c; size: 0x24.
extern "C" int State_InitializeWithZeroAndSetValue150(void *state) {
    PopulateOwnerThresholdSlotsAndResourceText(state, 0);
    Menu_QueueScriptEntry(state, 0x96);
    return 0;
}
