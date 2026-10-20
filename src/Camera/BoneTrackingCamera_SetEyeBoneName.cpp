#include <globaldefs.h>
extern "C" {
char *strcpy(char *, const char *);
void BoneTrackingCamera_RefreshTrackedBones(void *);
// Original: arm9/main @ 0x0204A440; symbol: func_0204a440; size: 0x24.
ARM void BoneTrackingCamera_SetEyeBoneName(void *param_1, const char *param_2) {
    char *dest = (char *)param_1 + 0x224;
    strcpy(dest, param_2);
    *(int *)((char *)param_1 + 0x254) = -1;
    BoneTrackingCamera_RefreshTrackedBones(param_1);
}
}
