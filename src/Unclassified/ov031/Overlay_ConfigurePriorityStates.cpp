#include <globaldefs.h>
ARM
extern "C" void *SelectStateWordByPriorityMask(unsigned mask);
extern "C" void func_ov031_02215528(void *first, void *state, void *fourth);
extern "C" int func_ov031_0220764c(void *state);
extern "C" void GameState_SetSelectedStateWordFields(unsigned mode);
extern "C" unsigned data_ov031_0224e1c0;
// Original: arm9/ov031 @ 0x02215358; symbol: func_ov031_02215358; size: 0x64.
extern "C" int Overlay_ConfigurePriorityStates(void *state) {
    void *first = SelectStateWordByPriorityMask(1);
    void *fourth = SelectStateWordByPriorityMask(4);
    func_ov031_02215528(first, state, fourth);
    data_ov031_0224e1c0 = 4;
    if (!func_ov031_0220764c(fourth)) return 12;
    GameState_SetSelectedStateWordFields(2);
    return 17;
}
