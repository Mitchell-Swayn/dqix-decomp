#include <globaldefs.h>
ARM
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" unsigned char *ReadWordFieldAtOffset150(void *);
extern "C" void RemoveHalfwordArrayElementAndShiftRemainingEightSlots(unsigned char*, int);
// Original: arm9/ov017 @ 0x021D0164; symbol: func_ov017_021d0164; size: 0x34.
extern "C" void World_RemoveObjectFromRecord(void *a, void *record, void *game_state) {
    unsigned char *entry = (unsigned char *)record;
    void *object = GameState_GetObjectWithFlag100(game_state, *(int *)(entry + 4));
    if (!object) return;
    unsigned char *array = ReadWordFieldAtOffset150(object);
    if (!array) return;
    RemoveHalfwordArrayElementAndShiftRemainingEightSlots(array, *(signed char *)(entry + 8));
}
