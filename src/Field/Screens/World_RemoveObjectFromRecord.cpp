#include <globaldefs.h>
ARM
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" unsigned char *GameObject_GetLinkedIndexedState(void *);
extern "C" void CharacterState_RemoveCarriedItemAtIndex(unsigned char*, int);
// Original: arm9/ov017 @ 0x021D0164; symbol: func_ov017_021d0164; size: 0x34.
extern "C" void World_RemoveObjectFromRecord(void *a, void *record, void *game_state) {
    unsigned char *entry = (unsigned char *)record;
    void *object = GameState_GetObjectWithFlag100(game_state, *(int *)(entry + 4));
    if (!object) return;
    unsigned char *array = GameObject_GetLinkedIndexedState(object);
    if (!array) return;
    CharacterState_RemoveCarriedItemAtIndex(array, *(signed char *)(entry + 8));
}
