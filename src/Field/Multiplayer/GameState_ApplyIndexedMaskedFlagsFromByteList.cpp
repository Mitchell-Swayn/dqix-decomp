#include <globaldefs.h>
ARM

extern "C" void *GameState_GetObjectWithFlag100(void *state, int index);
extern "C" unsigned char *GameObject_GetLinkedIndexedState(void *object);
extern "C" void CharacterState_LearnSpell(unsigned char *p, int bit);

struct EntryHeader { unsigned char index : 3; };

// Original: arm9/ov017 @ 0x021CCF70; symbol: func_ov017_021ccf70; size: 0x60.
extern "C" void GameState_ApplyIndexedMaskedFlagsFromByteList(void *unused, unsigned char *source, void *state) {
    unsigned char *entry = source + 4;
    void *object = GameState_GetObjectWithFlag100(state, ((EntryHeader *)entry)->index);
    if (object == 0) return;
    unsigned char *flags = GameObject_GetLinkedIndexedState(object);
    if (flags == 0) return;
    for (int i = 0; i < (int)(((unsigned int)entry[0] << 25) >> 28); i++) {
        unsigned char *slot = entry + i;
        CharacterState_LearnSpell(flags, slot[1]);
    }
}
