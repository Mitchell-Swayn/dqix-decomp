#include <globaldefs.h>
ARM
extern "C" void InitializeStoredVectorsAndInterpolationDefaults(char *);
extern "C" void Object_SetStateTwoAndClearWord218(int);
extern "C" void Object_InitializeTransformAndEmbeddedStateDefaults(unsigned int *);
// Original: arm9/ov004 @ 0x02163408; symbol: func_ov004_02163408; size: 0x24.
extern "C" void *InitializeObjectVectorsStateAndTransform(void *object) {
    InitializeStoredVectorsAndInterpolationDefaults((char *)object);
    Object_SetStateTwoAndClearWord218((int)object);
    Object_InitializeTransformAndEmbeddedStateDefaults((unsigned int *)object);
    return object;
}
