#include <globaldefs.h>
#include <Graphics/Vector.h>
ARM
#pragma optimization_level 4
// Original: arm9/main @ 0x020ADDA4; symbol: LinkedFieldActor_UpdateTrailingPoints; size: 0x204.
// Updates two linked positions and facing angles at a fixed separation.
extern "C" void LinkedFieldActor_UpdateTrailingPoints(char* p) {
 Vector3i position=*(Vector3i*)(p+0x44);
 Vector3i temp;
 Vector3i forward,first,second;
 Vector3i anchor1,anchor2;
 int angle=*(short*)(p+0xae);
 int cosine=fix32cos(angle);
 int sine=fix32sin(angle);
 forward.y=0;forward.z=cosine;forward.x=sine;
 cosine=fix32cos(*(int*)(p+0x170));
 sine=fix32sin(*(int*)(p+0x170));
 first.x=sine;first.z=cosine;first.y=0;
 cosine=fix32cos(*(int*)(p+0x180));
 sine=fix32sin(*(int*)(p+0x180));
 second.x=sine;second.y=0;second.z=cosine;
 Vector3fix_Normalize(&forward,&forward);
 Vector3fix_Normalize(&first,&first);
 Vector3fix_Normalize(&second,&second);
 temp=forward;
 Vector3fixMultiplyScalar(&temp,0xe66,&temp);
 Vector3fix_Subtract(&position,&temp,&anchor1);
 Vector3fix_Subtract(&anchor1,(Vector3i*)(p+0x164),&first);
 Vector3fix_Normalize(&first,&first);
 volatile Vector3i* vf=&first;
 int nx=vf->x,ny=vf->y;
 nx=-nx;
 int nz=vf->z;
 ny=-ny;nz=-nz;
 temp.x=nx;temp.y=ny;temp.z=nz;
 Vector3fixMultiplyScalar(&temp,0xe66,&temp);
 Vector3fix_Add(&anchor1,&temp,(Vector3i*)(p+0x164));
 *(int*)(p+0x170)=fix32_Atan2(first.x,first.z);
 *(int*)(p+0x170)=fix32ReduceAngle0To2Pi(*(int*)(p+0x170));
 temp=first;
 Vector3fixMultiplyScalar(&temp,0xe66,&temp);
 Vector3fix_Subtract((Vector3i*)(p+0x164),&temp,&anchor2);
 Vector3fix_Subtract(&anchor2,(Vector3i*)(p+0x174),&second);
 Vector3fix_Normalize(&second,&second);
 temp.x=-second.x;temp.y=-second.y;temp.z=-second.z;
 Vector3fixMultiplyScalar(&temp,0xe66,&temp);
 Vector3fix_Add(&anchor2,&temp,(Vector3i*)(p+0x174));
 *(int*)(p+0x180)=fix32_Atan2(second.x,second.z);
 *(int*)(p+0x180)=fix32ReduceAngle0To2Pi(*(int*)(p+0x180));
}
