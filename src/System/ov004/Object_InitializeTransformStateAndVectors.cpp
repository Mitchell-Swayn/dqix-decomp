#include <globaldefs.h>
ARM
extern "C" void Object_InitializeTransformAndEmbeddedStateDefaults(unsigned*);
extern "C" void Object_SetStateTwoAndClearWord218(int);
extern "C" void InitializeStoredVectorsAndInterpolationDefaults(char*);
// Original: arm9/ov004 @ 0x021633E4; symbol: func_ov004_021633e4; size: 0x24.
extern "C" void* Object_InitializeTransformStateAndVectors(unsigned int* p) { Object_InitializeTransformAndEmbeddedStateDefaults(p); Object_SetStateTwoAndClearWord218((int)p); InitializeStoredVectorsAndInterpolationDefaults((char*)p); return p; }
