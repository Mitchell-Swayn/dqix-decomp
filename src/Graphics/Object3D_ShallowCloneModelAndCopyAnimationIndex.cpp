#include <globaldefs.h>
#include <World/Object3D.h>
extern "C" {
// Original: arm9/main @ 0x02072ADC; symbol: func_02072adc; size: 0x20.
void Object3D_ShallowCloneModelAndCopyAnimationIndex(Object3D *p,Object3D *q){p->ShallowCloneModelAndAnimationsTo(q);*(short *)((char *)q+0x178)=*(int *)((char *)p+0xac);}
}
