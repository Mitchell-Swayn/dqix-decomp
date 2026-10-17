#include <globaldefs.h>
extern "C" char *strcpy(char *, const char *);
extern "C" void UntrackPreviouslyTrackedModelBones(int);
// Original: arm9/main @ 0x0204A488; symbol: func_0204a488; size: 0x24.
extern "C" void Object_Invokestrcpy(int param_1, const char *param_2) {
    strcpy((char *)(param_1 + 0x244), param_2);
    *(int *)(param_1 + 0x25c) = -1;
    UntrackPreviouslyTrackedModelBones(param_1);
}
