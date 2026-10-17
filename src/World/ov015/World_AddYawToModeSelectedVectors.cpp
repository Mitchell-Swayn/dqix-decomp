#include <globaldefs.h>
ARM
struct Vec {int x,y,z;};
struct State { char pad[0x450]; Vec v; };
extern "C" void __clear(void*,unsigned);
extern "C" void _ZN8Vector3iaSERKS_(Vec*,const Vec*);
extern "C" int _Z22fix32ReduceAngle0To2Pii(int);
// Original: arm9/ov015 @ 0x0218F5F8; symbol: func_ov015_0218f5f8; size: 0x19C.
extern "C" void World_AddYawToModeSelectedVectors(char* self,int angle) {
 Vec v;__clear(&v,12);
 switch(*(unsigned char*)(self+0x1c)) {
case 0:
 _ZN8Vector3iaSERKS_(&v,(Vec*)(*(char**)(self+0x24)+252));
 v.y=_Z22fix32ReduceAngle0To2Pii(v.y+angle);
 _ZN8Vector3iaSERKS_((Vec*)(*(char**)(self+0x24)+252),&v);
 _ZN8Vector3iaSERKS_(&v,(Vec*)(*(char**)(self+0x24)+80));
 v.y=_Z22fix32ReduceAngle0To2Pii(v.y+angle);
 _ZN8Vector3iaSERKS_((Vec*)(*(char**)(self+0x24)+80),&v);
 break;
case 1:
 _ZN8Vector3iaSERKS_(&v,&((State*)(*(char**)(self+0x24)+8))->v);
 v.y=_Z22fix32ReduceAngle0To2Pii(v.y+angle);
 _ZN8Vector3iaSERKS_(&((State*)(*(char**)(self+0x24)+8))->v,&v);
 _ZN8Vector3iaSERKS_(&v,(Vec*)(*(char**)(self+0x24)+252));
 v.y=_Z22fix32ReduceAngle0To2Pii(v.y+angle);
 _ZN8Vector3iaSERKS_((Vec*)(*(char**)(self+0x24)+252),&v);
 _ZN8Vector3iaSERKS_(&v,(Vec*)(*(char**)(self+0x24)+940));
 v.y=_Z22fix32ReduceAngle0To2Pii(v.y+angle);
 _ZN8Vector3iaSERKS_((Vec*)(*(char**)(self+0x24)+940),&v);
 _ZN8Vector3iaSERKS_(&v,(Vec*)(*(char**)(self+0x24)+80));
 v.y=_Z22fix32ReduceAngle0To2Pii(v.y+angle);
 _ZN8Vector3iaSERKS_((Vec*)(*(char**)(self+0x24)+80),&v);
 break;
default:
 _ZN8Vector3iaSERKS_(&v,(Vec*)(*(char**)(self+0x24)+80));
 v.y=_Z22fix32ReduceAngle0To2Pii(v.y+angle);
 _ZN8Vector3iaSERKS_((Vec*)(*(char**)(self+0x24)+80),&v);
 break;
 }
}
