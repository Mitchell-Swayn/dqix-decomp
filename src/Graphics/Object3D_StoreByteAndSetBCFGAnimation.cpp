#include <globaldefs.h>
#include <World/Object3D.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original: arm9/main @ 0x02041628; symbol: func_02041628; size: 0x18.
    bool Object3D_StoreByteAndSetBCFGAnimation(unsigned char *p,unsigned int value){
        p[744]=value;
        return ((Object3D *)p)->SetBCFGAnimationByIndex(value&255,0);
    }
}
