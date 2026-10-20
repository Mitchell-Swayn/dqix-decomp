#include <globaldefs.h>
ARM
extern "C" void GameState_AppendValueAndSetNodeFlags(void *, unsigned int, unsigned int);
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);

// Original: arm9/ov004 @ 0x0215CC14; symbol: func_ov004_0215cc14; size: 0x2C.
extern "C" int Menu_HideMarketRootAndResumeListingSelection(void *state) {
    GameState_AppendValueAndSetNodeFlags(state, 2, 8);
    Menu_QueueScriptEntry(state, 0x396);
    return 0;
}
