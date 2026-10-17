#include <globaldefs.h>
ARM
// Original: arm9/ov001 @ 0x021598BC; symbol: func_ov001_021598bc; size: 0x24.
extern "C" int Util_AdvanceField64UntilLimit(void *limitObject, void *counterObject) {
    int counter = *(int *)((char *)counterObject + 0x64);
    if (counter >= *(int *)((char *)limitObject + 0x10)) {
        *(int *)((char *)counterObject + 0x64) = 0;
        return 0;
    }
    *(int *)((char *)counterObject + 0x64) = counter + 1;
    return 1;
}
