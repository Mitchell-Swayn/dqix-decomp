#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void Object3D_InitializeExtendedAnimationDefaults(void *);
// Original: arm9/main @ 0x0204128C; symbol: func_0204128c; size: 0xC.
    void Object3D_InitializeExtendedRecord(void *p){
        Object3D_InitializeExtendedAnimationDefaults(p);
    }
}
