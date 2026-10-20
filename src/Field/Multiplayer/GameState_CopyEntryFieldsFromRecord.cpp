#include <globaldefs.h>
ARM
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" unsigned char *GameObject_GetLinkedIndexedState(void*);
// Original: arm9/ov017 @ 0x021CCA00; symbol: func_ov017_021cca00; size: 0x5C.
extern "C" void GameState_CopyEntryFieldsFromRecord(void *unused, unsigned char *record, void *game) {
    unsigned char *fields = record + 4;
    void *object = GameState_GetObjectWithFlag100(game, *(unsigned short *)fields);
    if (!object) return;
    unsigned char *state = GameObject_GetLinkedIndexedState(object);
    if (!state) return;
    *(unsigned short *)(state + 0x954) = *(unsigned short *)(fields + 2);
    int i = 0;
    while (i < 12) {
        unsigned char value = *(fields + i + 4);
        i++;
        unsigned char *destination = state + i;
        destination[0x186] = value;
    }
}
