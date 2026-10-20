#include <globaldefs.h>
ARM
extern "C" void *GameState_GetObjectWithFlag100(void *object, int index);
extern "C" void GameObject_RequestQueuedActionCompletion(unsigned char *p);
// Original: arm9/ov017 @ 0x021CC320; symbol: func_ov017_021cc320; size: 0x20.
extern "C" void Field_ApplyMemberQueuedActionCompletion(void *unused, void *record, void *object) {
    unsigned char index = *((unsigned char *)record + 4);
    void *found = GameState_GetObjectWithFlag100(object, index);
    if (found)
        GameObject_RequestQueuedActionCompletion((unsigned char *)found);
}
