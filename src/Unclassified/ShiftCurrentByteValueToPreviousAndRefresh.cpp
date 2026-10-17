#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void Object3D_UpdateVisibilityAndAlphaByKind(void *);
// Original: arm9/main @ 0x02033B88; symbol: func_02033b88; size: 0x18.
    void ShiftCurrentByteValueToPreviousAndRefresh(unsigned char *p,unsigned char value){
        p[191]=p[190];
        p[190]=value;
        Object3D_UpdateVisibilityAndAlphaByKind(p);
    }
}
