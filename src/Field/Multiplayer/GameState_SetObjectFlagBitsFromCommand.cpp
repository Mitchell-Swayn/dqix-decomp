#include <globaldefs.h>
ARM

extern "C" void *GameState_GetObjectWithFlag100(void *state, int index);

struct FlagCommand {
    unsigned int unused;
    int index;
    unsigned int mask;
    int enabled;
};

// Original: arm9/ov017 @ 0x021CEE34; symbol: func_ov017_021cee34; size: 0x44.
extern "C" void GameState_SetObjectFlagBitsFromCommand(void *unused, FlagCommand *command, void *state) {
    int enabled = command->enabled;
    unsigned int mask = command->mask;
    int index = command->index;
    void *object = GameState_GetObjectWithFlag100(state, index);
    if (object == 0) return;
    if (enabled) *(unsigned int *)((char *)object + 0x18c) |= mask;
    else *(unsigned int *)((char *)object + 0x18c) &= ~mask;
}
