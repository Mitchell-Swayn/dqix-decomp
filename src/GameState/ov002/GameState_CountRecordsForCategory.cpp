#include <globaldefs.h>
ARM

extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetIndexList(void *);
extern "C" int Object_CountNonzeroFlagBytes(char *);
extern "C" void *GameState_GetObjectWithFlag100(void *, int);
extern "C" unsigned char *ReadWordFieldAtOffset150(void *);
extern "C" int CountEightPositiveHalfwordSlots(char *);

// Original: arm9/ov002 @ 0x02157108; symbol: func_ov002_02157108; size: 0x6C.
extern "C" int GameState_CountRecordsForCategory(void *state, int category) {
    void *instance = _ZN9GameState11GetInstanceEv();
    int count = 0;
    if (category == 5) {
        char *list = (char *)GameState_GetIndexList(instance);
        count = Object_CountNonzeroFlagBytes(list + 0xE04);
    } else if (category == 4) {
        count = Object_CountNonzeroFlagBytes((char *)GameState_GetIndexList(instance));
    } else {
        void *object = GameState_GetObjectWithFlag100(instance, category);
        if (object != 0) {
            count = CountEightPositiveHalfwordSlots((char *)ReadWordFieldAtOffset150(object));
        }
    }
    return count;
}
