#include <globaldefs.h>
ARM
// Original: arm9/ov001 @ 0x02158470; symbol: func_ov001_02158470; size: 0x24.
extern "C" int GameState_AdvanceBoundedCounter(void *limitObject, void *counterObject) {
    int count = *(int *)((char *)counterObject + 0x44);
    int limit = *(int *)((char *)limitObject + 0x1c);
    if (count >= limit) {
        *(int *)((char *)counterObject + 0x44) = 0;
        return 0;
    }
    *(int *)((char *)counterObject + 0x44) = count + 1;
    return 1;
}
