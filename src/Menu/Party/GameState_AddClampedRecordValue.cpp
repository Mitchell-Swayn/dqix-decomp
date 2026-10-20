#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" unsigned char *GameObject_GetLinkedIndexedState(void *);
// Original: arm9/ov002 @ 0x02154944; symbol: func_ov002_02154944; size: 0x84.
extern "C" short GameState_AddClampedRecordValue(void *unused, int id, int amount, unsigned char *result) {
    char *object = (char *)GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(), id);
    if (!object) return 0;
    GameObject_GetLinkedIndexedState(object);
    char *record = *(char **)(object + 0x130);
    char *limits = *(char **)(object + 0x134);
    int limit = *(unsigned short *)(limits + 0x32);
    int current = *(unsigned short *)(record + 6);
    int next = current + amount;
    int delta;
    if (next >= limit) {
        delta = limit - current;
        if (delta == 0) *result = 0;
        else *result = 3;
    } else {
        *result = 3;
        delta = next - current;
    }
    *(unsigned short *)(*(char **)(object + 0x130) + 6) = current + delta;
    return delta;
}
