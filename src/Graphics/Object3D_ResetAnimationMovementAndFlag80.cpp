#include <globaldefs.h>
#include <World/Object3D.h>
extern "C" {
    void GameObject_SetMotionState(void *,int);
    void GameObject_SetMotionStateAndRefreshAnimation(void *,int);
// Original: arm9/main @ 0x02076DA0; symbol: func_02076da0; size: 0x54.
    bool Object3D_ResetAnimationMovementAndFlag80(Object3D *object){
        unsigned char *p=(unsigned char *)object;
        if(!*(int *)(p+304))GameObject_SetMotionState(p,0);
        else GameObject_SetMotionStateAndRefreshAnimation(p,0);
        *(short *)(p+176)=808;
        *(short *)(p+178)=0;
        *(short *)(p+180)=0;
        object->DisableFlag(128);
        p[378]=0;
        return true;
    }
}
