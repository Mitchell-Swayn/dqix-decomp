#include <globaldefs.h>
ARM
struct Vec {int v[3];};
extern "C" int _Z22fix32ReduceAngle0To2Pii(int);
extern "C" void _ZN8Vector3iaSERKS_(Vec*,const Vec*);
extern "C" int Input_TestKeyMask(unsigned short*,unsigned short);
extern "C" unsigned short data_02114e30[];
// Original: arm9/ov008 @ 0x02186E4C; symbol: func_ov008_02186e4c; size: 0x298.
extern "C" void World_UpdateYawFromKeysOrTarget(char* self,unsigned ticks) {
 if(*(unsigned*)(self+0xb18)&0x40) {
 Vec angle=*(Vec*)(self+0x7e0);
 int done=0;
 int distance=_Z22fix32ReduceAngle0To2Pii(0x5ccc-angle.v[1]);
 int yaw;
 if(distance>=0&&distance<0x3244) {
 yaw=angle.v[1]+distance/12;
 for(unsigned i=0;i<ticks-1;i++)yaw+=_Z22fix32ReduceAngle0To2Pii(0x5ccc-yaw)/12;
 } else if(distance>=0x3244&&distance<0x6488) {
 yaw=angle.v[1]-(0x6488-distance)/12;
 for(unsigned i=0;i<ticks-1;i++)yaw-=(0x6488-_Z22fix32ReduceAngle0To2Pii(0x5ccc-yaw))/12;
 }
 angle.v[1]=_Z22fix32ReduceAngle0To2Pii(yaw);
 _ZN8Vector3iaSERKS_((Vec*)(self+0x7e0),&angle);
 distance=_Z22fix32ReduceAngle0To2Pii(0x5ccc-angle.v[1]);
 int magnitude=distance<0?-distance:distance;
 if(magnitude<40)done=1;
 else {
 int residual=0x6488-distance;if(residual<0)residual=-residual;
 if(residual<40)done=1;
 }
 if(done) {
 angle.v[1]=_Z22fix32ReduceAngle0To2Pii(0x5ccc);
 _ZN8Vector3iaSERKS_((Vec*)(self+0x7e0),&angle);
 *(unsigned*)(self+0xb18)&=~0x40;
 }
 } else if(*(unsigned*)(self+0xb18)&0x20) {
 int left=0,right=0;
 if(Input_TestKeyMask(data_02114e30,0x200))left=1;
 if(Input_TestKeyMask(data_02114e30,0x100))right=1;
 if(left&&right)*(unsigned*)(self+0xb18)|=0x40;
 else if(left||right) {
 Vec angle=*(Vec*)(self+0x7e0);
 if(left)angle.v[1]+=(int)(4096.0f*(0.08f*(float)ticks));
 if(right)angle.v[1]-=(int)(4096.0f*(0.08f*(float)ticks));
 angle.v[1]=_Z22fix32ReduceAngle0To2Pii(angle.v[1]);
 _ZN8Vector3iaSERKS_((Vec*)(self+0x7e0),&angle);
 }
 }
}
