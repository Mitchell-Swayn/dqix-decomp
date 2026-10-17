#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetIndexList(void *);
extern "C" void *GameState_GetObjectWithFlag100(void *, int);
extern "C" bool Object_TestNestedOffset138Word14Bit0(void *);
// Original: arm9/ov023 @ 0x021ED92C; symbol: func_ov023_021ed92c; size: 0x5C.
extern "C" bool GameState_CheckAllIndexedObjectsNestedFlagSet(void) {
    void *state = _ZN9GameState11GetInstanceEv();
    unsigned char *list = (unsigned char *)GameState_GetIndexList(state);
    int i = 0;
    while (i < list[0xf7c]) {
        int index = *(unsigned char *)(list + i + 0xf78);
        void *object = GameState_GetObjectWithFlag100(state, index);
        if (object && !Object_TestNestedOffset138Word14Bit0(object)) return false;
        ++i;
    }
    return true;
}
