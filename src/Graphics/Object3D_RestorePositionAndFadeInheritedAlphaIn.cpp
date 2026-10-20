#include <globaldefs.h>
#include <World/Object3D.h>
extern "C" {
    void Object_InvokeStateMethodAndRecordSuccessfulTransition(Object3D *,int);
// Original: arm9/main @ 0x02077630; symbol: func_02077630; size: 0x70.
    void Object3D_RestorePositionAndFadeInheritedAlphaIn(Object3D *p){
        if(p->GetInheritedAlpha()!=0&&p->GetInheritedAlpha()!=31)return;
        if(!p->GetInheritedAlpha()){
            *(Vector3i *)((unsigned char *)p+68)=*(Vector3i *)((unsigned char *)p+344);
            p->TransitionInheritedAlpha(31,250);
        }if(p->GetInheritedAlpha()!=31)return;
        Object_InvokeStateMethodAndRecordSuccessfulTransition(p,1);
    }
}
