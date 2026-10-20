#include <globaldefs.h>
int fix32ReduceAngle0To2Pi(int);
extern "C" {
ARM void Object3D_SetRotationComponents(void*,int,int,int);
// Original: arm9/main @ 0x02041378; symbol: func_02041378; size: 0xF8.
 void Object3D_AdvanceYawTowardTargetWithFixedStep(unsigned char* self,int,int delta) { int target=*(int*)(self+176),current=*(int*)(self+84);if(current==target)return;if(current<target){delta=target-current;if(delta>12868)delta-=25736;}else if(target<current){delta=-(current-target);if(delta<-12868)delta+=25736;}bool changed=false;if(delta>0){if(delta>=819)delta=fix32ReduceAngle0To2Pi(current+819);else delta=target;changed=true;*(unsigned short*)(self+172)|=2;}else if(delta<0){if(-delta>=819)delta=fix32ReduceAngle0To2Pi(current-819);else delta=target;changed=true;*(unsigned short*)(self+172)|=2;}if(!changed)*(unsigned short*)(self+172)&=~2;Object3D_SetRotationComponents(self,*(int*)(self+80),delta,*(int*)(self+88)); }
}
