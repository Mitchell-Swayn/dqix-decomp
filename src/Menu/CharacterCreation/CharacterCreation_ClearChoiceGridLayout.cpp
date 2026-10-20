#include <globaldefs.h>
ARM
struct SelectionSlots { int slots[8]; };
// Original: arm9/ov009 @ 0x021847C4; symbol: func_ov009_021847c4; size: 0x28.
extern "C" void CharacterCreation_ClearChoiceGridLayout(SelectionSlots* state) {
 state->slots[1]=-1; state->slots[0]=-1; state->slots[3]=-1; state->slots[2]=-1;
 state->slots[4]=-1; state->slots[5]=-1; state->slots[6]=-1; state->slots[7]=-1;
}
