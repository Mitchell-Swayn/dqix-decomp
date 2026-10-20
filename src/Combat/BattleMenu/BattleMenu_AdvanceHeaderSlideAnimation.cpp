#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02180B50; symbol: Object_AdvanceCountdownAndSetCompletionState; size: 0x5C.
// Initializes a 0x180 countdown; while active, subtracts three times the rate at +0x94C, clamps at 0x80, and marks completion with state -1.
extern "C" void BattleMenu_AdvanceHeaderSlideAnimation(void *state) {
    int stateValue = *(int *)((unsigned char *)state + 0x934);
    if (stateValue == 0) {
        *(int *)((unsigned char *)state + 0x930) = 0x180;
        *(int *)((unsigned char *)state + 0x938) = 0;
        *(int *)((unsigned char *)state + 0x934) = 1;
    } else if (stateValue == 1) {
        int value = *(int *)((unsigned char *)state + 0x930) -
            3 * *(int *)((unsigned char *)state + 0x94c);
        *(int *)((unsigned char *)state + 0x930) = value;
        if (value <= 0x80) {
            *(int *)((unsigned char *)state + 0x930) = 0x80;
            *(int *)((unsigned char *)state + 0x934) = -1;
        }
    }
}
