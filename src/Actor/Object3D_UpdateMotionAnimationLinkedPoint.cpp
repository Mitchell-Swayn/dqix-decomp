#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void Object3D_AdvanceMotionAnimationAndLinkedPoint(void *);
// Original: arm9/main @ 0x02048144; symbol: func_02048144; size: 0xC.
    void Object3D_UpdateMotionAnimationLinkedPoint(void *p){
        Object3D_AdvanceMotionAnimationAndLinkedPoint(p);
    }
}
