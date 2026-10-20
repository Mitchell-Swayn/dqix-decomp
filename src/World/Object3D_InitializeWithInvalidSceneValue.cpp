#include <globaldefs.h>
#include <World/Object3D.h>
extern "C" {
// Original: arm9/main @ 0x02072AC4; symbol: func_02072ac4; size: 0x18.
void Object3D_InitializeWithInvalidSceneValue(Object3D *p){p->Initialize();*(int *)((char *)p+0xac)=-1;}
}
