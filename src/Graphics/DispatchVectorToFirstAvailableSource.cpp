#include <globaldefs.h>
#include "Graphics/Vector.h"
extern "C" void SetTargetPositionAndNormalizedDirection(void*,Vector3fix*);
extern "C" void Object3D_SetMovementTargetAndSelectAnimation(void*,Vector3fix*);
struct Sources
{
    unsigned char pad[20];
    void* first;
    void* second;
};
// Original: arm9/main @ 0x020409B0; symbol: func_020409b0; size: 0x30.
extern "C" ARM void DispatchVectorToFirstAvailableSource(Sources* p,Vector3fix* value)
{
    if(p->first)
    {
        SetTargetPositionAndNormalizedDirection(p->first,value);
        return;
    }if(!p->second)return;
    Object3D_SetMovementTargetAndSelectAnimation(p->second,value);
}
